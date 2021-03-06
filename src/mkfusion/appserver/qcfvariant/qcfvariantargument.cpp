#include "qcfvariantargument.h"

QCFVariantArgument::QCFVariantArgument()
{
}

QCFVariantArgument::QCFVariantArgument(const QString &name, const QString &required, const QString &type, const QString &def, const QString &displayName, const QString &hint)
    : m_Name(name)
    , m_Required(required)
    , m_Type(type)
    , m_Default(def)
    , m_DisplayName(displayName)
    , m_Hint(hint)
{
}

QCFVariantArgument::QCFVariantArgument(const QCFVariantArgument &other)
    : m_Name(other.m_Name)
    , m_Required(other.m_Required)
    , m_Type(other.m_Type)
    , m_Default(other.m_Default)
    , m_DisplayName(other.m_DisplayName)
    , m_Hint(other.m_Hint)
{
}

QCFVariantArgument &QCFVariantArgument::operator=(const QCFVariantArgument &other)
{
    m_Name = other.m_Name;
    m_Required = other.m_Required;
    m_Type = other.m_Type;
    m_Default = other.m_Default;
    m_DisplayName = other.m_DisplayName;
    m_Hint = other.m_Hint;

    return *this;
}
