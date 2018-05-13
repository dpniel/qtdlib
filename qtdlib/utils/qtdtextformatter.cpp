#include "qtdtextformatter.h"
#include <QCoreApplication>
#include <QTextCursor>
#include <QTextCharFormat>
#include <QStringBuilder>

QTdTextFormatter::QTdTextFormatter(QObject *parent) : QObject(parent),
    m_textDocument(Q_NULLPTR), m_content(Q_NULLPTR)
{
    connect (this, &QTdTextFormatter::textDocumentChanged, this, [this] {
        if (QTextDocument * doc = m_textDocument->textDocument ()) {
            connect (doc, &QTextDocument::contentsChange, this, &QTdTextFormatter::doFormat);
            doFormat();
        }
    });

    connect(this, &QTdTextFormatter::textDocumentChanged, this, &QTdTextFormatter::doFormat);
    connect(this, &QTdTextFormatter::contentChanged, this, &QTdTextFormatter::doFormat);
}

QQuickTextDocument *QTdTextFormatter::textDocument() const
{
    return m_textDocument;
}

QTdFormattedText *QTdTextFormatter::content() const
{
    return m_content;
}

QColor QTdTextFormatter::linkColor() const
{
    return m_linkColor;
}

QColor QTdTextFormatter::codeColor() const
{
    return m_codeColor;
}

void QTdTextFormatter::setTextDocument(QQuickTextDocument *textDocument)
{
    if (m_textDocument == textDocument)
        return;

    m_textDocument = textDocument;
    emit textDocumentChanged(m_textDocument);
}

void QTdTextFormatter::setContent(QTdFormattedText *content)
{
    if (m_content == content)
        return;

    m_content = content;
    emit contentChanged(m_content);
}

void QTdTextFormatter::setLinkColor(QColor linkColor)
{
    if (m_linkColor == linkColor)
        return;

    m_linkColor = linkColor;
    emit linkColorChanged(m_linkColor);
}

void QTdTextFormatter::setCodeColor(QColor codeColor)
{
    if (m_codeColor == codeColor)
        return;

    m_codeColor = codeColor;
    emit codeColorChanged(m_codeColor);
}

void QTdTextFormatter::doFormat()
{
    if (!m_textDocument->textDocument() || !m_content) {
        return;
    }

    const QList<QTdTextEntity*> entities = m_content->entities()->toList();
    QTextDocument *doc = m_textDocument->textDocument();
    if (doc->isEmpty()) {
        return;
    }
    const QString rawText = doc->toRawText();
    for (const QTdTextEntity *entity : entities) {
        QTextCursor cursor{ doc };
        cursor.setPosition(entity->offset(), QTextCursor::MoveAnchor);
        cursor.setPosition(entity->offset() + entity->length(), QTextCursor::KeepAnchor);
        const QString subText = rawText.mid(entity->offset(), entity->length());
        switch(entity->entityType()->type()) {
        case QTdTextEntity::TEXT_ENTITY_TYPE_BOLD:
        {
            QTextCharFormat format;
            format.setFontWeight(60);
            cursor.mergeCharFormat(format);
            break;
        }
        case QTdTextEntity::TEXT_ENTITY_TYPE_BOT_COMMAND:
        case QTdTextEntity::TEXT_ENTITY_TYPE_CASHTAG:
            break;
        case QTdTextEntity::TEXT_ENTITY_TYPE_CODE:
        case QTdTextEntity::TEXT_ENTITY_TYPE_PRE:
        case QTdTextEntity::TEXT_ENTITY_TYPE_PRE_CODE:
        {
            QTextCharFormat format;
            format.setFontFamily("Ubuntu Mono");
            format.setFontFixedPitch(true);
            if (m_codeColor.isValid()) {
                format.setForeground(m_codeColor);
            }
            cursor.mergeCharFormat(format);
            break;
        }
        case QTdTextEntity::TEXT_ENTITY_TYPE_EMAIL_ADDRESS:
        {
            QTextCharFormat format;
            format.setAnchor(true);
            format.setAnchorHref("mailto:" % subText);
            if (m_linkColor.isValid()) {
                format.setForeground(m_linkColor);
            }
            cursor.mergeCharFormat(format);
            break;
        }
        case QTdTextEntity::TEXT_ENTITY_TYPE_ITALIC:
        {
            QTextCharFormat format;
            format.setFontItalic(true);
            cursor.mergeCharFormat(format);
            break;
        }
        case QTdTextEntity::TEXT_ENTITY_TYPE_HASHTAG:
        case QTdTextEntity::TEXT_ENTITY_TYPE_MENTION:
        case QTdTextEntity::TEXT_ENTITY_TYPE_MENTION_NAME:
        {
            QTextCharFormat format;
            format.setAnchor(true);
            format.setAnchorHref(subText);
            if (m_linkColor.isValid()) {
                format.setForeground(m_linkColor);
            }
            cursor.mergeCharFormat(format);
            break;
        }
        case QTdTextEntity::TEXT_ENTITY_TYPE_PHONE_NUMBER:
        {
            QTextCharFormat format;
            format.setAnchor(true);
            format.setAnchorHref("tel:" % subText);
            if (m_linkColor.isValid()) {
                format.setForeground(m_linkColor);
            }
            cursor.mergeCharFormat(format);
            break;
        }
        case QTdTextEntity::TEXT_ENTITY_TYPE_TEXT_URL:
            break;
        case QTdTextEntity::TEXT_ENTITY_TYPE_URL:
        {
            QTextCharFormat format;
            format.setAnchor(true);
            format.setAnchorHref(subText);
            format.setFontUnderline(true);
            if (m_linkColor.isValid()) {
                format.setForeground(m_linkColor);
            }
            cursor.mergeCharFormat(format);
            break;
        }
        default:
            break;
        }
    }
}
