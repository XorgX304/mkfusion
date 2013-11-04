#ifndef QCFVARIANTARGUMENT_H
#define QCFVARIANTARGUMENT_H

#include <QString>


class QCFVariantArgument
{
public:
    QCFVariantArgument();
    QCFVariantArgument(const QCFVariantArgument &other);
#ifdef Q_COMPILER_RVALUE_REFS
    QCFVariantArgument &operator=(QCFVariantArgument &&other);
#endif
    QCFVariantArgument &operator=(const QCFVariantArgument &other);

    QString m_Name;
    QString m_Required;
    QString m_Type;
    QString m_Default;
};

#endif // QCFVARIANTARGUMENT_H
