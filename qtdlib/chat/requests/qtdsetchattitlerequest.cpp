#include "qtdsetchattitlerequest.h"

QTdSetChatTitleRequest::QTdSetChatTitleRequest(QObject *parent) : QTdRequest(parent),
    m_chatId(0)
{

}

void QTdSetChatTitleRequest::setTitle(const qint64 &chatId, const QString &title)
{
    m_chatId = chatId;
    m_title = title;
}

QJsonObject QTdSetChatTitleRequest::marshalJson()
{
    return QJsonObject{
        {"@type", "setChatTitle"},
        {"chat_id", m_chatId},
        {"title", m_title},
    };
}
