#ifndef QCFPARSER_H
#define QCFPARSER_H

struct QCFParserElement;
struct QCFParserTag;
class QCFParser;

#include "qcfgenerator.h"
#include "qcffunction.h"
#include "qcftag.h"

#include <QObject>
#include <QString>
#include <QList>
#include <QHash>

enum QCFParserElementType {Boolean, Number, String, Variable, Function, Operator, SharpExpression, CodeBlock, Expression, SubExpression, Parameters, Parameter, CFScript, CFComment, CFTagExpression, CFTagArguments, CFTagArgument, ObjectFunction, VariableIndex, Keyword, Error};
enum QCFParserErrorType {NoError, ForcedTerminationError, ParsingError, InvalidCloseTagError, InvalidCFTagError, InvalidArgumentError, InvalidArgumentTypeError, InvalidNestedTagPositionError};
enum QCFParserTagType {UnknownTagType, CFTagType, EndCFTagType, CommentTagType, ExpressionTagType};
enum QCFParserMode {FullParseMode, CompilerMode};

struct QCFParserElement
{
	QCFParserElementType m_Type;
	QString m_Text;
	int m_Position;
	int m_Size;
	QList<QCFParserElement> m_ChildElements;
};

struct QCFParserTag
{
	int m_Start;
	int m_Length;
	QString m_Name;
	QCFParserTagType m_TagType;
	QCFParserElement m_Arguments;
	bool m_InlineClosedTag;
    struct QCFParserTag *m_OtherTag;
};

quint32 GetLineNumberFromPosition(const QString &, const qint32);
quint32 GetColumnNumberFromPosition(const QString &, const qint32);

qint32 FindEndString(QString, qint32);

class QCFParser : public QObject
{
private:
	QList<QCFParserTag> m_Tags;
	QHash<QString, QCFTag> m_CFTagsDef;
	QHash<QString, QCFFunction> m_CFFunctionsDef;
	quint32 m_ErrorPosition;
	QString m_Error;
	QString m_Text;
	QCFParserMode m_Mode;
    static bool TrimCFCode(const QString &p_Text, int &p_Offset);
    bool isValidVarChar(const QString &p_Text, int index);
    QCFParserElement ParseCFCode(const QString &p_Text, const qint32 p_Offset, const QCFParserElementType p_ElementType, QCFParserElement *parent);
    quint32 FindCFCommentSize(const QString &p_Text, quint32 p_Position);
public:
	QCFParser();
	explicit QCFParser(QCFParserMode mode);
	QString getError();
    const QString &getText() const;
	quint32 getErrorPosition();
    QCFParserErrorType Parse(const QString &p_Text, bool *p_Terminate = NULL);
	QCFParserErrorType BuildTagTree();
	QCFParserErrorType validate();
	QList<QCFParserTag> getTags();
	QString m_FileName;
	qint64 m_CFMFileSize;
	uint m_CFMModifyDateTime;
	bool m_InsideCFScript;

    friend class QCFGenerator;
};

#endif // QCFPARSER_H
