#pragma once

#include "qabstractrdsservice.h"
#include <QObject>
#include <QString>
#include <QVector>
#include <QList>
#include <QMap>

class QDefaultService : public QAbstractRDSService
{
public:
    enum Command
    {
        IdeDefaultCommand
    };

    QDefaultService() : QAbstractRDSService() {}
    virtual ~QDefaultService() {}
    virtual QByteArray ExecuteRDSCommand(QRDSServer &rdsserver, quint8 command, const QMap<QString, QString> &map);

private:
    QByteArray IdeDefault(QRDSServer &);
};
