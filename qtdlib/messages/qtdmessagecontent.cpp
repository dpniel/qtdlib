#include "qtdmessagecontent.h"

QTdMessageContent::QTdMessageContent(QObject *parent) : QTdObject(parent)
{
}

QTdMessageText::QTdMessageText(QObject *parent) : QTdMessageContent(parent),
    m_text(Q_NULLPTR), m_webPage(Q_NULLPTR)
{
    setType(MESSAGE_TEXT);
}

QTdFormattedText *QTdMessageText::text() const
{
    return m_text;
}

QTdWebPage *QTdMessageText::webPage() const
{
    return m_webPage;
}

void QTdMessageText::unmarshalJson(const QJsonObject &json)
{
    m_text = new QTdFormattedText(this);
    m_text->unmarshalJson(json["text"].toObject());
    if (json.contains("web_page")) {
        m_webPage = new QTdWebPage(this);
        m_webPage->unmarshalJson(json["web_page"].toObject());
    }
    emit dataChanged();
}
