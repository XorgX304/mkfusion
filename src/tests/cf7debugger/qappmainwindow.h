#ifndef QAPPMAINWINDOW_H
#define QAPPMAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include "qjdwpdebugger.h"

class QAppMainWindow : public QMainWindow
{
	Q_OBJECT
public:
    QAppMainWindow(QWidget *parent = 0, Qt::WindowFlags flags = 0);
private:
	QListView* m_Edit;
	QJDWPDebugger* m_jdwpsocket;
};

#endif // QAPPMAINWINDOW_H
