#pragma once

#include <QString>
#include <QObject>
#include <QList>

class QCFFunctionArgument : public QObject
{
public:
    enum QCFFunctionArgumentType {TypeConstant, TypeExpression, TypeVariable, TypeAny};
    enum QCFFunctionArgumentDataType {ArgumentDataTypeBool, ArgumentDataTypeInt, ArgumentDataTypeDouble, ArgumentDataTypeString, ArgumentDataTypeBinary, ArgumentDataTypeDateTime, ArgumentDataTypeQCFVariant, ArgumentDataTypeAny};

    QCFFunctionArgument();
    QCFFunctionArgument(const QCFFunctionArgument &other);
    QCFFunctionArgument(QCFFunctionArgumentDataType p_DataType, bool p_Required = false, QCFFunctionArgumentType p_Type = QCFFunctionArgument::TypeExpression);
    QCFFunctionArgument &operator=(const QCFFunctionArgument &other);
#ifdef Q_COMPILER_RVALUE_REFS
    inline QCFFunctionArgument &operator=(QCFFunctionArgument &&other)
    {
        qSwap(m_DataType, other.m_DataType);
        qSwap(m_Required, other.m_Required);
        qSwap(m_Type, other.m_Type);

        return *this;
    }
#endif

    // Class members
    QCFFunctionArgumentDataType m_DataType;
    QCFFunctionArgumentType m_Type;
    bool m_Required;
};

class QCFFunction : public QObject
{
public:
    enum QCFFunctionReturnType {ReturnVoid, ReturnBool, ReturnInt, ReturnDouble, ReturnBinary, ReturnString, ReturnDateTime, ReturnQCFVariant};

    QCFFunction();
    QCFFunction(const QCFFunction &other);
    QCFFunction(const QString &p_FunctionName, QCFFunctionReturnType p_ReturnType, bool p_NeedsThis = false);
    QCFFunction &operator=(const QCFFunction &other);
#ifdef Q_COMPILER_RVALUE_REFS
    inline QCFFunction &operator=(QCFFunction &&other)
    {
        qSwap(m_Name, other.m_Name);
        qSwap(m_NeedsThis, other.m_NeedsThis);
        qSwap(m_ReturnType, other.m_ReturnType);
        qSwap(m_Arguments, other.m_Arguments);

        return *this;
    }
#endif
    void setName(const QString &p_FunctionName);
    QString getName();

    // Class members
    QString m_Name;
    bool m_NeedsThis;
    QCFFunctionReturnType m_ReturnType;
    QList<QCFFunctionArgument> m_Arguments;
};
