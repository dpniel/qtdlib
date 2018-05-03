#include "qtdsetpinnedchatsrequest.h"
#include <QJsonArray>

QTdSetPinnedChatsRequest::QTdSetPinnedChatsRequest(QObject *parent) : QTdRequest(parent)
{
}

void QTdSetPinnedChatsRequest::setPinnedChats(const QList<qint64> &chatIds)
{
    m_chatIds = chatIds;
}

QJsonObject QTdSetPinnedChatsRequest::marshalJson()
{
    QJsonArray ids;
    for (const qint64 &id : m_chatIds) {
        ids << QJsonValue(id);
    }
    return QJsonObject{
        {"@type", "setPinnedChats"},
        {"chat_ids", ids},
    };
}
