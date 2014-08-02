#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui
{
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = 0);
    virtual ~Dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Dialog *ui;

private slots:
    void on_urlslist_itemDoubleClicked(QListWidgetItem *item);
    void on_start_clicked();
};

#endif // MAINDIALOG_H
