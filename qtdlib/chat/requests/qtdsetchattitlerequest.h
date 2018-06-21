#ifndef QTDSETCHATTITLEREQUEST_H
#define QTDSETCHATTITLEREQUEST_H

#include <QObject>
#include "common/qtdrequest.h"

class QTdSetChatTitleRequest : public QTdRequest
{
    Q_OBJECT
    Q_DISABLE_COPY(QTdSetChatTitleRequest)
    QString m_title;
    qint64 m_chatId;
public:
    explicit QTdSetChatTitleRequest(QObject *parent = nullptr);

    void setTitle(const qint64 &chatId, const QString &title);
    QJsonObject marshalJson();
};

#endif // QTDSETCHATTITLEREQUEST_H
