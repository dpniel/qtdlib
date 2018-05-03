#ifndef QTDSETPINNEDCHATSREQUEST_H
#define QTDSETPINNEDCHATSREQUEST_H

#include <QObject>
#include "common/qtdrequest.h"

class QTdSetPinnedChatsRequest : public QTdRequest
{
    Q_OBJECT
    QList<qint64> m_chatIds;
public:
    explicit QTdSetPinnedChatsRequest(QObject *parent = nullptr);

    void setPinnedChats(const QList<qint64> &chatIds);
    QJsonObject marshalJson();
};

#endif // QTDSETPINNEDCHATSREQUEST_H
