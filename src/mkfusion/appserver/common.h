#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include "qwddx.h"

struct QCFRunningTemplate_Request
{
	QString m_AuthType;
	QString m_User;
	QString m_Filename;
	QString m_Accept;
	QString m_AcceptEncoding;
	QString m_AcceptLanguage;
	QString m_Connection;
	QString m_RemoteHost;
	QString m_Referer;
	QString m_UserAgent;
	QString m_Args;
	QString m_Method;
	QString m_Protocol;
	QString m_Host;
	QString m_URI;
};

#ifdef Q_WS_WIN
#define MY_EXPORT __declspec(dllexport)
#else
#define MY_EXPORT
#endif

QString getCurrentExecutableFileName();
void log(const QString &p_filename, const QString& p_Line);

extern "C" MY_EXPORT QString mk_cfdump(const QWDDX&);

#endif // COMMON_H
