#ifndef QTDSETPINNEDCHATSREQUEST_H
#define QTDSETPINNEDCHATSREQUEST_H

#include <QObject>
#include "common/qtdrequest.h"

class QTdSetPinnedChatsRequest : public QTdRequest
{
    Q_OBJECT
    Q_DISABLE_COPY(QTdSetPinnedChatsRequest)
    QList<qint64> m_chatIds;
public:
    explicit QTdSetPinnedChatsRequest(QObject *parent = nullptr);

    void setPinnedChats(const QList<qint64> &chatIds);
    QJsonObject marshalJson();
};

#endif // QTDSETPINNEDCHATSREQUEST_H
