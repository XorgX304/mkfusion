#include "qcfcompiler.h"

#include <QFileInfo>
#include <QProcess>
#include <QFile>
#include <QDir>

QCFCompiler::QCFCompiler(const QString &p_MKFusionPath)
    : m_MKFusionPath(p_MKFusionPath)
{
}

QString QCFCompiler::compile(const QString &p_Target)
{
    QFileInfo file(p_Target);
    QString l_NewTarget = file.baseName();
    QProcess process;

    // Compile
#ifdef Q_OS_WIN
    QString l_QtPath = QDir::toNativeSeparators(m_MKFusionPath) + "bin\\qt\\";
    QString l_MingwPath = QDir::toNativeSeparators(m_MKFusionPath) + "bin\\mingw\\";
    process.start(l_MingwPath + "bin\\g++.exe", QStringList()
#elif defined Q_OS_LINUX
    process.start("g++", QStringList()
#else
#error Windows and Linux OSs are currently supported.
#endif

        << "-c"

#ifdef __x86_64__
        << "-m64"
#endif

#ifdef Q_OS_LINUX
        << "-pipe"
#endif

#ifdef __arm__
        << "-march=armv6" << "-mfloat-abi=hard" << "-mfpu=vfp"
#endif

#ifdef QT_NO_DEBUG
        << "-O2"
#else
    << "-g"
#endif

#ifdef __arm__
        << "-pipe" << "-fstack-protector" << "--param=ssp-buffer-size=4"
#endif

        << "-std=c++0x"

#ifdef Q_OS_WIN
        << "-frtti" << "-fexceptions" << "-mthreads"
#endif

        << "-Wall"

#ifdef Q_OS_LINUX
        << "-Wall" << "-W" << "-D_REENTRANT" << "-fPIE"
#endif

#ifdef Q_OS_WIN
        << "-DQT_LARGEFILE_SUPPORT" << "-DQT_DLL"
#endif

#ifdef QT_NO_DEBUG
    << "-DQT_NO_DEBUG"
#endif

    << "-DQT_CORE_LIB"

#ifdef Q_OS_LINUX
        << "-DQT_SHARED"
#endif

#ifdef Q_OS_WIN
        << "-DQT_THREAD_SUPPORT"
#endif

#ifdef Q_OS_WIN
        << "-I" << (l_MingwPath + "include")
        << "-I" << (l_QtPath + "include" + QDir::separator() + "QtCore")
        << "-I" << (l_QtPath + "include" + QDir::separator() + "QtNetwork")
        << "-I" << (l_QtPath + "include" + QDir::separator() + "QtConcurrent")
        << "-I" << (l_QtPath + "include")
        << "-I" << (m_MKFusionPath + "include")
#elif defined Q_OS_LINUX
    #ifdef __x86_64__
        << "-I" << "/usr/share/qt5/mkspecs/linux-g++-64"
        << "-I" << "/usr/lib/qt/mkspecs/linux-g++-64" // Arch linux uses this path
    #else
        << "-I" << "/usr/share/qt5/mkspecs/linux-g++"
        << "-I" << "/usr/lib/qt/mkspecs/linux-g++" // Arch linux uses this path
    #endif
        << "-I" << "."
        << "-I" << "/usr/include/qt5/QtCore"
        << "-I" << "/usr/include/qt5/QtNetwork"
        << "-I" << "/usr/include/qt5/QtConcurrent"
        << "-I" << "/usr/include/qt5"
        << "-I" << "/usr/include/qt/QtCore" // Arch linux uses this path
        << "-I" << "/usr/include/qt/QtNetwork" // Arch linux uses this path
        << "-I" << "/usr/include/qt/QtConcurrent" // Arch linux uses this path
        << "-I" << "/usr/include/qt" // Arch linux uses this path
        << "-I" << (m_MKFusionPath + "include")
#endif

        << "-o" << (m_MKFusionPath + "templates" + QDir::separator() + l_NewTarget + ".o")
        << (m_MKFusionPath + "templates" + QDir::separator() + l_NewTarget + ".cpp")
    );

    bool finished = process.waitForFinished(-1);

#ifdef QT_NO_DEBUG
    QFile::remove(m_MKFusionPath+"templates/"+l_NewTarget+".cpp");
#endif

    if ((finished == false)||(process.exitCode() != 0))
    {
        return "compile error: " + QString::fromUtf8(process.readAllStandardError()) + QString::fromUtf8(process.readAllStandardOutput());
    }

    // Link
#ifdef Q_OS_WIN
    process.start(l_MingwPath + "bin\\g++.exe", QStringList()
#elif defined Q_OS_LINUX
    process.start("g++", QStringList()
#else
#error Windows and Linux OSs are currently supported.
#endif

#ifdef __x86_64__
        << "-m64"
#endif

#if defined Q_OS_LINUX && defined QT_NO_DEBUG
        << "-Wl,-O1"
#endif

#ifdef Q_OS_WIN
        << "-Wl,-enable-stdcall-fixup" << "-Wl,-enable-auto-import" << "-Wl,-enable-runtime-pseudo-reloc"
    #ifdef QT_NO_DEBUG
        << "-Wl,-s"
    #endif
        << "-mthreads"
#endif

        << "-shared"

#ifdef Q_OS_WIN
        << "-o" << (m_MKFusionPath + "templates" + QDir::separator() + l_NewTarget + ".dll")
#else
        << "-o" << (m_MKFusionPath + "templates" + QDir::separator() + l_NewTarget + ".so")
#endif

        << (m_MKFusionPath + "templates" + QDir::separator() + l_NewTarget + ".o")

#ifdef Q_OS_WIN
        << "-L" << (l_QtPath + "lib") << (m_MKFusionPath + "lib\\mkfusion.a")
#else
        << "-L/usr/lib/x86_64-linux-gnu" << "-lrt" << "-lpthread"
#endif

#if defined Q_OS_WIN && !defined QT_NO_DEBUG
        << "-lQt5Concurrentd" << "-lQt5Cored"
#else
        << "-lQt5Concurrent" << "-lQt5Core"
#endif
    );

    finished = process.waitForFinished(-1);

    QFile::remove(m_MKFusionPath+"templates/"+l_NewTarget+".o");

    if ((finished == false)||(process.exitCode() != 0))
    {
        return "link error: " + process.readAllStandardError() + process.readAllStandardOutput();
    }

    return "";
}