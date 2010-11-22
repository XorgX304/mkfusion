#ifndef QDETAIL_H
#define QDETAIL_H

#include "qcfparser.h"

#include <QDialog>
#include <QTreeWidgetItem>

namespace Ui {
    class QDetail;
}

class QDetail : public QDialog
{
    Q_OBJECT

public:
    explicit QDetail(QWidget *parent = 0);
    ~QDetail();

    void setFileForParsing(const QString&);

private:
    Ui::QDetail *ui;

    void addSubTrees(const QCFParserElement&, QTreeWidgetItem*);
    void recolor();
    void colorElement(const QCFParserElement&, const QString&);
    QCFParser m_Parser;
    QString m_CurrentTextSegment;
    bool m_IsCurrentSelect;

private slots:
    void on_treeWidget_currentItemChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous);
};

#endif // QDETAIL_H
