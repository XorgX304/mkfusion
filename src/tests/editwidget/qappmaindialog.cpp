#include "qappmaindialog.h"
#include "qcodeeditwidget.h"
#include "ui_qappmaindialog.h"

QAppMainDialog::QAppMainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QAppMainDialog)
{
    ui->setupUi(this);

    QCodeEditWidget *widget = new QCodeEditWidget(this);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setFileExtension("cfm");
    widget->setText("1ako\n2ako\n3ako\n4ako\n5ako\n6ako\n<cfset a = 12 />\n");

    ui->gridLayout->addWidget(widget, 0, 0, 1, 1);
}

QAppMainDialog::~QAppMainDialog()
{
    delete ui;
    ui = 0;
}

void QAppMainDialog::changeEvent(QEvent *e)
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
