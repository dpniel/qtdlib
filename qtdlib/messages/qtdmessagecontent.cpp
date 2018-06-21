#include "qtdmessagecontent.h"

QTdMessageContent::QTdMessageContent(QObject *parent) : QTdObject(parent)
{
}

QTdMessageText::QTdMessageText(QObject *parent) : QTdMessageContent(parent),
    m_text(new QTdFormattedText), m_webPage(new QTdWebPage), m_hasWebPage(false)
{
    setType(MESSAGE_TEXT);
}

QTdFormattedText *QTdMessageText::text() const
{
    return m_text.data();
}

QTdWebPage *QTdMessageText::webPage() const
{
    if (!m_hasWebPage) {
        return Q_NULLPTR;
    }
    return m_webPage.data();
}

void QTdMessageText::unmarshalJson(const QJsonObject &json)
{
    m_hasWebPage = false;
    m_text->unmarshalJson(json["text"].toObject());
    if (json.contains("web_page")) {
        m_webPage->unmarshalJson(json["web_page"].toObject());
        m_hasWebPage = true;
    }
    emit dataChanged();
}
