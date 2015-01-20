#include "qdetail.h"
#include "ui_qdetail.h"
#include "qcfparser.h"
#include "qtextparsercompat.h"

#include <QFile>
#include <QList>
#include <QFont>

QDetail::QDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QDetail)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags() | Qt::WindowMinMaxButtonsHint);

#ifdef Q_OS_WIN
    QFont l_Font = QFont("Courier", 10, 0, false);
#else
    QFont l_Font = QFont("Monospace", 9, 0, false);
#endif
    ui->textEdit->setFont(l_Font);
}

QDetail::~QDetail()
{
    delete ui;
    ui = 0;
}

void QDetail::setFileForParsing(const QString &p_File)
{
    QString fileContent;

    // Read file from file
    {
        QFile file(p_File);
        file.open(QIODevice::ReadOnly);
        fileContent = file.readAll();
        file.close();
    }

    ui->textEdit->setPlainText(fileContent);

    // Setup old parser
    {
        QCFParser oldParser;

        if (oldParser.parse(fileContent) == NoError)
        {
            oldParser.prioritizeOperators();
        }

        ui->status_label->setText(oldParser.error());

        m_OldParserTags = oldParser.getTags();

        ushort c = 0;

        for(const QCFParserTag &tag: m_OldParserTags)
        {
            QString name;

            switch(tag.m_TagType)
            {
            case UnknownTagType:
                name = "UnknownCFTag";
                break;
            case CFTagType:
                name = "BeginCFTag(" + tag.m_Name + ")";
                break;
            case EndCFTagType:
                name = "EndCFTag(" + tag.m_Name + ")";
                break;
            case CommentTagType:
                name = "CFComment";
                break;
            case ExpressionTagType:
                name = "CFExpression";
                break;
            }

            QTreeWidgetItem *widgetItem = new QTreeWidgetItem();

            widgetItem->setText(0, name);
            widgetItem->setText(1, QChar(c));

            addSubTrees(tag.m_Arguments, widgetItem);

            ui->old_parser_treeWidget->addTopLevelItem(widgetItem);

            c++;
        }
    }

    // Setup new parser
    {
        QTextParserCompat newParser;

        QTextParserElements elements = newParser.parseText(fileContent, "cfm");

        m_NewParserTags = newParser.toOldParser(elements);

        ushort c = 0;

        for(const QCFParserTag &tag: m_NewParserTags)
        {
            QString name;

            switch(tag.m_TagType)
            {
            case UnknownTagType:
                name = "UnknownCFTag";
                break;
            case CFTagType:
                name = "BeginCFTag(" + tag.m_Name + ")";
                break;
            case EndCFTagType:
                name = "EndCFTag(" + tag.m_Name + ")";
                break;
            case CommentTagType:
                name = "CFComment";
                break;
            case ExpressionTagType:
                name = "CFExpression";
                break;
            }

            QTreeWidgetItem *widgetItem = new QTreeWidgetItem();

            widgetItem->setText(0, name);
            widgetItem->setText(1, QChar(c));

            addSubTrees(tag.m_Arguments, widgetItem);

            ui->new_parser_treeWidget->addTopLevelItem(widgetItem);

            c++;
        }
    }

    ui->old_parser_treeWidget->expandAll();
    ui->new_parser_treeWidget->expandAll();

    recolor();

    // Set focus to old_parser tree widget
    ui->old_parser_treeWidget->setFocus();
}

void QDetail::addSubTrees(const QCFParserElement &p_ParserElement, QTreeWidgetItem *p_WidgetItem)
{
    ushort c = 0;

    for(const QCFParserElement &element: p_ParserElement.m_ChildElements)
    {
        QString name;

        //enum QCFParserElementType {Boolean, Number, String, Variable, Function, Operator, SharpExpression
        //Expression, SubExpression, Parameters, Parameter, CFScript, CFComment, CFTagExpression, CFTagArguments, CFTagArgument, ObjectFunction, VariableMember, Error};

        switch(element.m_Type)
        {
        case Boolean:
            name = "Boolean(" + element.m_Text + ")";
            break;
        case Number:
            name = "Number(" + element.m_Text + ")";
            break;
        case String:
            name = "String(" + element.m_Text + ")";
            break;
        case Variable:
            name = "Variable(" + element.m_Text + ")";
            break;
        case Function:
            name = "Function(" + element.m_Text + ")";
            break;
        case Operator:
            name = "Operator(" + element.m_Text + ")";
            break;
        case SharpExpression:
            name = "SharpExpression";
            break;
        case CodeBlock:
            name = "CodeBlock";
            break;
        case Expression:
            name = "Expression";
            break;
        case SubExpression:
            name = "SubExpression";
            break;
        case Parameters:
            name = "Parameters";
            break;
        case Parameter:
            name = "Parameter";
            break;
        case CFScript:
            name = "CFScript";
            break;
        case CFComment:
            name = "CFComment";
            break;
        case CFTagExpression:
            name = "CFTagExpression";
            break;
        case CFTagArguments:
            name = "CFTagArguments";
            break;
        case CFTagArgument:
            name = "CFTagArgument";
            break;
        case ObjectFunction:
            name = "ObjectFunction(" + element.m_Text + ")";
            break;
        case VariableMember:
            name = "VariableMember(" + element.m_Text + ")";
            break;
        case Keyword:
            name = "Keyword(" + element.m_Text + ")";
            break;
        case Error:
            name = "Error(" + element.m_Text + ")";
            break;
        default:
            name = "[Unknown](" + element.m_Text + ")";
            break;
        }

        QTreeWidgetItem *widgetItem = new QTreeWidgetItem();

        widgetItem->setText(0, name);
        widgetItem->setText(1, p_WidgetItem->text(1) + QChar(c));

        addSubTrees(element, widgetItem);

        p_WidgetItem->addChild(widgetItem);

        c++;
    }
}

void QDetail::recolor()
{
    QTextCursor cursor = ui->textEdit->textCursor();

    ushort c = 0;

    if (ui->old_parser_treeWidget->hasFocus())
    {
        for(const QCFParserTag &tag: m_OldParserTags)
        {
            QString TagString = QChar(c);

            if ((!m_CurrentTextSegment.isEmpty())&&(m_CurrentTextSegment.left(1) != TagString))
            {
                c++;

                continue;
            }

            cursor.setPosition(tag.m_Start, QTextCursor::MoveAnchor);
            ui->textEdit->setTextCursor(cursor);
            cursor.setPosition(tag.m_Start + tag.m_Length, QTextCursor::KeepAnchor);
            ui->textEdit->setTextCursor(cursor);

            if ((TagString == m_CurrentTextSegment))
            {
                if (m_IsCurrentSelect)
                {
                    ui->textEdit->setTextBackgroundColor(QColor(255, 128, 128));
                }
                else
                {
                    ui->textEdit->setTextBackgroundColor(QColor(255, 255, 255));
                }

                cursor.setPosition(tag.m_Start, QTextCursor::MoveAnchor);
                ui->textEdit->setTextCursor(cursor);

                break;
            }

            if (tag.m_TagType == CommentTagType)
            {
                ui->textEdit->setTextColor(QColor(128, 128, 128));
            }
            else
            {
                ui->textEdit->setTextColor(QColor(128, 0, 0));
            }

            colorElement(tag.m_Arguments, TagString);

            cursor.setPosition(tag.m_Start, QTextCursor::MoveAnchor);
            ui->textEdit->setTextCursor(cursor);

            c++;
        }
    }
    else if (ui->new_parser_treeWidget->hasFocus())
    {
        for(const QCFParserTag &tag: m_NewParserTags)
        {
            QString TagString = QChar(c);

            if ((!m_CurrentTextSegment.isEmpty())&&(m_CurrentTextSegment.left(1) != TagString))
            {
                c++;

                continue;
            }

            cursor.setPosition(tag.m_Start, QTextCursor::MoveAnchor);
            ui->textEdit->setTextCursor(cursor);
            cursor.setPosition(tag.m_Start + tag.m_Length, QTextCursor::KeepAnchor);
            ui->textEdit->setTextCursor(cursor);

            if ((TagString == m_CurrentTextSegment))
            {
                if (m_IsCurrentSelect)
                {
                    ui->textEdit->setTextBackgroundColor(QColor(255, 128, 128));
                }
                else
                {
                    ui->textEdit->setTextBackgroundColor(QColor(255, 255, 255));
                }

                cursor.setPosition(tag.m_Start, QTextCursor::MoveAnchor);
                ui->textEdit->setTextCursor(cursor);

                break;
            }

            if (tag.m_TagType == CommentTagType)
            {
                ui->textEdit->setTextColor(QColor(128, 128, 128));
            }
            else
            {
                ui->textEdit->setTextColor(QColor(128, 0, 0));
            }

            colorElement(tag.m_Arguments, TagString);

            cursor.setPosition(tag.m_Start, QTextCursor::MoveAnchor);
            ui->textEdit->setTextCursor(cursor);

            c++;
        }
    }
}

void QDetail::colorElement(const QCFParserElement &p_Element, const QString &p_ElementIDString)
{
    QTextCursor cursor = ui->textEdit->textCursor();

    cursor.setPosition(p_Element.m_Position, QTextCursor::MoveAnchor);
    ui->textEdit->setTextCursor(cursor);
    cursor.setPosition(p_Element.m_Position + p_Element.m_Size, QTextCursor::KeepAnchor);
    ui->textEdit->setTextCursor(cursor);

    if (!m_CurrentTextSegment.isEmpty())
    {
        if ((p_ElementIDString.left(m_CurrentTextSegment.length()) == m_CurrentTextSegment))
        {
            if (m_IsCurrentSelect)
            {
                ui->textEdit->setTextBackgroundColor(QColor(255, 128, 128));
            }
            else
            {
                ui->textEdit->setTextBackgroundColor(QColor(255, 255, 255));
            }
        }
    }

    switch (p_Element.m_Type)
    {
    case CFTagArguments:
        //ui->textEdit->setTextColor(QColor(255, 128, 0));
        break;
    case CFTagArgument:
        ui->textEdit->setTextColor(QColor(255, 255, 0));
        break;
    case Variable:
        ui->textEdit->setTextColor(QColor(128, 128, 0));
        break;
    case Operator:
        ui->textEdit->setTextColor(QColor(0, 0, 0));
        break;
    case Number:
        ui->textEdit->setTextColor(QColor(0, 255, 0));
        break;
    case String:
        ui->textEdit->setTextColor(QColor(0, 0, 255));
        break;
    case SharpExpression:
        ui->textEdit->setTextColor(QColor(72, 72, 0));
        break;
    case Expression:
        ui->textEdit->setTextColor(QColor(92, 92, 0));
        break;
    case CFComment:
        ui->textEdit->setTextColor(QColor(128, 128, 128));
        break;
    default:
        break;
    }

    ushort c = 0;

    for(const QCFParserElement &l_ChildElement: p_Element.m_ChildElements)
    {
        colorElement(l_ChildElement, p_ElementIDString + QChar(c));

        c++;
    }
}

void QDetail::on_old_parser_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    if (previous)
    {
        m_CurrentTextSegment = previous->text(1);
        m_IsCurrentSelect = false;
        recolor();
    }

    if (current)
    {
        m_CurrentTextSegment = current->text(1);
        m_IsCurrentSelect = true;
        recolor();
    }
}

void QDetail::on_new_parser_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    if (previous)
    {
        m_CurrentTextSegment = previous->text(1);
        m_IsCurrentSelect = false;
        recolor();
    }

    if (current)
    {
        m_CurrentTextSegment = current->text(1);
        m_IsCurrentSelect = true;
        recolor();
    }
}
