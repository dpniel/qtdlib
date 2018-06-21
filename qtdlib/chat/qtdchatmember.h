#ifndef QTDCHATMEMBER_H
#define QTDCHATMEMBER_H

#include <QObject>
#include <QPointer>
#include <QDateTime>
#include "user/qtduser.h"
#include "qtdchatmemberstatus.h"
#include "qtdchataction.h"

/**
 * @brief The QTdChatMember class
 *
 * https://core.telegram.org/tdlib/docs/classtd_1_1td__api_1_1chat_member.html
 */
class QTdChatMember : public QTdObject
{
    Q_OBJECT
    Q_PROPERTY(QString userId READ qmlUserId NOTIFY chatMemberChanged)
    Q_PROPERTY(QTdUser *user READ user NOTIFY userChanged)
    Q_PROPERTY(QString inviteUserId READ qmlInviteUserId NOTIFY chatMemberChanged)
    Q_PROPERTY(QDateTime joinedChatDate READ qmlJoinedChatDate NOTIFY chatMemberChanged)
    Q_PROPERTY(QTdChatMemberStatus *status READ status NOTIFY chatMemberChanged)
    // TODO: botInfo https://core.telegram.org/tdlib/docs/classtd_1_1td__api_1_1bot_info.html
public:
    explicit QTdChatMember(QObject *parent = nullptr);

    QString qmlUserId() const;
    qint32 userId() const;
    QTdUser *user() const;
    QString qmlInviteUserId() const;
    qint32 inviteUserId() const;
    QDateTime qmlJoinedChatDate() const;
    qint32 joinedChatDate() const;
    QTdChatMemberStatus *status() const;

    void unmarshalJson(const QJsonObject &json);
    // TODO: allow admins to set status on a member
//    Q_INVOKABLE void setStatus();

signals:
    void chatMemberChanged();
    void userChanged();

private slots:
    void isUserAvailable(const qint32 &userId);

private:
    Q_DISABLE_COPY(QTdChatMember)
    QTdInt32 m_userId;
    QTdInt32 m_inviteUserId;
    QTdInt32 m_joinedChatDate;
    QPointer<QTdChatMemberStatus> m_status;
    bool m_waitingForUser;
};

#endif // QTDCHATMEMBER_H
