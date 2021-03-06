#include "maindialog.h"
#include "ui_maindialog.h"

#include "comparedialog.h"

#include <QApplication>
#include <QStringList>
#include <QTcpSocket>
#include <QColor>
//#include <QHttp>
#include <QUrlQuery>
#include <QUrl>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

QByteArray getUrlContent(QString url)
{
    QUrl qurl(url);
    QTcpSocket socket;
    QByteArray send, recieved;

    int port = qurl.port();
    if (port == -1)
    {
        port = 80;
    }

    socket.connectToHost(qurl.host(), port);

    if (!socket.waitForConnected())
    {
        return QByteArray();
    }

    send = "GET ";
    send.append(qurl.path(QUrl::EncodeSpaces | QUrl::EncodeUnicode | QUrl::EncodeDelimiters | QUrl::EncodeReserved).toUtf8());
    send.append("\r\n\r\n");

    socket.write(send);

    if (!socket.waitForBytesWritten())
    {
        return QByteArray();
    }

    while(socket.state() == QAbstractSocket::ConnectedState)
    {
        socket.waitForReadyRead();

        recieved.append(socket.readAll());
    }

    return recieved;
}

void Dialog::on_start_clicked()
{
    QByteArray l_ba = getUrlContent(ui->urledit->text());

    {
        int l_tablebeg = l_ba.indexOf("<table");
        if (l_tablebeg < 0)
        {
            return;
        }
        int l_tableend = l_ba.indexOf("</table>", l_tablebeg);
        if (l_tableend < 0)
        {
            return;
        }

        l_ba = l_ba.mid(l_tablebeg, l_tableend - l_tablebeg + 8);
    }

    QString l_buf = l_ba;
    l_ba.clear();

    QStringList l_rows;

    {
        int l_pos = 0;

        while(1)
        {
            int l_trfrom = l_buf.indexOf("<tr", l_pos, Qt::CaseInsensitive);
            if (l_trfrom < 0)
            {
                break;
            }

            int l_trto = l_buf.indexOf("</tr>", l_pos, Qt::CaseInsensitive);
            if (l_trto < 0)
            {
                break;
            }

            l_rows.append(l_buf.mid(l_trfrom, l_trto - l_trfrom + 5));

            l_pos = l_trto + 5;
        }
    }

    l_buf.clear();
    ui->urlslist->clear();

    for(int c = 3; c < l_rows.size() - 1; c++)
    {
        QStringList l_cols;
        l_cols.clear();

        int l_pos = 0;
        forever
        {
            int l_tdfrom = l_rows[c].indexOf("<td", l_pos, Qt::CaseInsensitive);
            if (l_tdfrom < 0)
            {
                break;
            }

            int l_tdto = l_rows[c].indexOf("</td>", l_pos, Qt::CaseInsensitive);
            if (l_tdto < 0)
            {
                break;
            }

            l_cols.append(l_rows[c].mid(l_tdfrom, l_tdto - l_tdfrom + 5));

            l_pos = l_tdto + 5;
        }

        if (l_cols.size() >= 2)
        {
            QString l_filename;

            {
                QString l_cell = l_cols[1];
                int l_cellfrom = l_cell.indexOf("href=\"", 0, Qt::CaseInsensitive);
                if (l_cellfrom < 0)
                {
                    break;
                }

                int l_cellto = l_cell.indexOf("\"", l_cellfrom + 6, Qt::CaseInsensitive);
                if (l_cellto < 0)
                {
                    break;
                }

                l_filename = l_cell.mid(l_cellfrom + 6, l_cellto - l_cellfrom - 6);
            }

            if ((l_filename.isEmpty())||((!l_filename.endsWith(".cfm", Qt::CaseInsensitive))&&(!l_filename.endsWith(".cfc", Qt::CaseInsensitive))))
            {
                continue;
            }

            ui->urlslist->addItem(l_filename);

            QString m_cffile = ui->urledit->text() + l_filename;
            QString m_mffile = ui->urledit->text() + l_filename;
            m_mffile[m_mffile.length() - 3] = 'm';

            QApplication::processEvents();
            QByteArray l_cf = getUrlContent(m_cffile);

            QApplication::processEvents();
            QByteArray l_mf = getUrlContent(m_mffile);

            if (l_cf != l_mf)
            {
                ui->urlslist->item(ui->urlslist->count() - 1)->setBackground(Qt::red);
            }
        }
    }

    ui->urlslist->setFocus();
}

void Dialog::on_urlslist_itemDoubleClicked(QListWidgetItem *item)
{

    QString l_filename = item->text();

    QString m_cffile = ui->urledit->text() + l_filename;
    QString m_mffile = ui->urledit->text() + l_filename;
    m_mffile[m_mffile.length() - 3] = 'm';

    CompareDialog *dlg = new CompareDialog(this);
    dlg->setLeftText(getUrlContent(m_cffile));
    dlg->setRightText(getUrlContent(m_mffile));
    dlg->updateEditors();

    dlg->show();
}
