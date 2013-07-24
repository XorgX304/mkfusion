#ifndef QAPPMAINDIALOG_H
#define QAPPMAINDIALOG_H

#include <QDialog>

namespace Ui {
    class QAppMainDialog;
}

class QAppMainDialog : public QDialog {
    Q_OBJECT
public:
    explicit QAppMainDialog(QWidget *parent = 0);
    virtual ~QAppMainDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::QAppMainDialog *ui;
};

#endif // QAPPMAINDIALOG_H
