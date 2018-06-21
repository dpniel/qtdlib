#include "qtdchatmember.h"
#include "user/qtdusers.h"
#include "client/qtdclient.h"
#include "qtdchatactionfactory.h"

QTdChatMember::QTdChatMember(QObject *parent) : QTdObject(parent),
    m_userId(0), m_inviteUserId(0), m_joinedChatDate(0), m_status(Q_NULLPTR),
    m_waitingForUser(false)
{
    setType(CHAT_MEMBER);
}

QString QTdChatMember::qmlUserId() const
{
    return m_userId.toQmlValue();
}

qint32 QTdChatMember::userId() const
{
    return m_userId.value();
}

QTdUser *QTdChatMember::user() const
{
    return QTdUsers::instance()->model()->getByUid(qmlUserId());
}

QString QTdChatMember::qmlInviteUserId() const
{
    return m_inviteUserId.toQmlValue();
}

qint32 QTdChatMember::inviteUserId() const
{
    return m_inviteUserId.value();
}

QDateTime QTdChatMember::qmlJoinedChatDate() const
{
    return QDateTime::fromTime_t(m_joinedChatDate.value());
}

qint32 QTdChatMember::joinedChatDate() const
{
    return m_joinedChatDate.value();
}

QTdChatMemberStatus *QTdChatMember::status() const
{
    return m_status;
}

void QTdChatMember::unmarshalJson(const QJsonObject &json)
{
    m_userId = json["user_id"];
    m_inviteUserId = json["inviter_user_id"];
    m_joinedChatDate = json["joined_chat_date"];

    if (m_status) {
        m_status->deleteLater();
    }
    const QJsonObject status = json["status"].toObject();
    const QString type = status["@type"].toString();
    if (type == "chatMemberStatusAdministrator") {
        m_status = new QTdChatMemberStatusAdmin(this);
    } else if (type == "chatMemberStatusBanned") {
        m_status = new QTdChatMemberStatusBanned(this);
    } else if (type == "chatMemberStatusCreator") {
        m_status = new QTdChatMemberStatusCreator(this);
    } else if (type == "chatMemberStatusLeft") {
        m_status = new QTdChatMemberStatusLeft(this);
    } else if (type == "chatMemberStatusMember") {
        m_status = new QTdChatMemberStatusMember(this);
    } else if (type == "chatMemberStatusRestricted") {
        m_status = new QTdChatMemberStatusRestricted(this);
    }

    if (m_status) {
        m_status->unmarshalJson(status);
    }
    emit chatMemberChanged();

    auto *users = QTdUsers::instance()->model();
    if (users->getByUid(qmlUserId())) {
        emit userChanged();
        return;
    }
    connect(QTdUsers::instance(), &QTdUsers::userCreated, this, &QTdChatMember::isUserAvailable);
    QTdClient::instance()->send(QJsonObject{
                                    {"@type", "getUser"},
                                    {"user_id", m_userId.value()}
                                });
    m_waitingForUser = true;
}


void QTdChatMember::isUserAvailable(const qint32 &userId)
{
    if (userId != m_userId.value()) {
        return;
    }
    if (m_waitingForUser) {
        disconnect(QTdUsers::instance(), &QTdUsers::userCreated, this, &QTdChatMember::isUserAvailable);
        m_waitingForUser = false;
    }
    emit userChanged();
}
