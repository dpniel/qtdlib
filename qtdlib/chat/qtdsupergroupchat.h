#ifndef QTDSUPERGROUPCHAT_H
#define QTDSUPERGROUPCHAT_H

#include <QObject>
#include <QPointer>
#include "qtdchat.h"
#include "qtdchatmemberstatus.h"

class QTdSuperGroupChat : public QTdChat
{
    Q_OBJECT
    Q_PROPERTY(QString superGroupId READ qmlSuperGroupId NOTIFY superGroupChanged)
    Q_PROPERTY(QString userName READ userName NOTIFY superGroupChanged)
    Q_PROPERTY(QDateTime date READ qmlDate NOTIFY superGroupChanged)
    Q_PROPERTY(QTdChatMemberStatus* status READ status NOTIFY superGroupChanged)
    Q_PROPERTY(bool anyoneCanInvite READ anyoneCanInvite NOTIFY superGroupChanged)
    Q_PROPERTY(bool signMessages READ signMessages NOTIFY superGroupChanged)
    Q_PROPERTY(bool isChannel READ isChannel NOTIFY superGroupChanged)
    Q_PROPERTY(bool isVerified READ isVerified NOTIFY superGroupChanged)
    Q_PROPERTY(QString restrictionReason READ restrictionReason NOTIFY superGroupChanged)

    // SuperGroupFullInfo properties
    Q_PROPERTY(QString description READ description NOTIFY superGroupInfoChanged)
    Q_PROPERTY(QString memberCount READ qmlMemberCount NOTIFY superGroupInfoChanged)
    Q_PROPERTY(QString adminCount READ qmlAdminCount NOTIFY superGroupInfoChanged)
    Q_PROPERTY(QString restrictedCount READ qmlRestrictedCount NOTIFY superGroupInfoChanged)
    Q_PROPERTY(QString bannedCount READ qmlBannedCount NOTIFY superGroupInfoChanged)
    Q_PROPERTY(bool isAllHistoryAvailable READ isHistoryAvailable NOTIFY superGroupInfoChanged)
    Q_PROPERTY(QString stickerSetId READ qmlStickerSetId NOTIFY superGroupInfoChanged)
    Q_PROPERTY(QString inviteLink READ inviteLink NOTIFY superGroupInfoChanged)
    Q_PROPERTY(QString pinnedMessageId READ qmlPinnedMessageId NOTIFY superGroupInfoChanged)
    Q_PROPERTY(QString upgradedFromBasicGroupId READ qmlUpgradedFromBasicGroupId NOTIFY superGroupInfoChanged)
    Q_PROPERTY(QString upgradedFromMaxMessageId READ qmlUpgradedFromMaxMessageId NOTIFY superGroupInfoChanged)
public:
    explicit QTdSuperGroupChat(QObject *parent = nullptr);

    QString qmlSuperGroupId() const;
    qint32 superGroupId() const;
    QString userName() const;
    QDateTime qmlDate() const;
    qint32 date() const;
    QTdChatMemberStatus* status() const;
    QString qmlMemberCount() const;
    qint32 memberCount() const;
    bool anyoneCanInvite() const;
    bool signMessages() const;
    bool isChannel() const;
    bool isVerified() const;
    QString restrictionReason() const;
    QString description() const;
    QString qmlAdminCount() const;
    qint32 adminCount() const;
    QString qmlRestrictedCount() const;
    qint32 restrictedCount() const;
    QString qmlBannedCount() const;
    qint32 bannedCount() const;
    bool isHistoryAvailable() const;
    QString qmlStickerSetId() const;
    qint64 stickerSetId() const;
    QString inviteLink() const;
    QString qmlPinnedMessageId() const;
    qint64 pinnedMessageId() const;
    QString qmlUpgradedFromBasicGroupId() const;
    qint32 upgradedFromBasicGroupId() const;
    QString qmlUpgradedFromMaxMessageId() const;
    qint64 upgradedFromMaxMessageId() const;
signals:
    void superGroupChanged();
    void superGroupInfoChanged();

protected:
    virtual void onChatOpened();

private slots:
    void getSuperGroupData();
    void updateSuperGroup(const QJsonObject &json);
    void updateSuperGroupFullInfo(const QJsonObject &json);
    void handleSuperGroupFullInfo(const QJsonObject &json);
    void superGroupFullInfo(const QJsonObject &info);
private:
    Q_DISABLE_COPY(QTdSuperGroupChat)
    QTdInt32 m_sgId;
    QString m_username;
    qint32 m_date;
    QPointer<QTdChatMemberStatus> m_status;
    QTdInt32 m_memberCount;
    bool m_canInvite;
    bool m_signMessages;
    bool m_isChannel;
    bool m_isVerified;
    QString m_restrictionReason;
    QString m_description;
    QTdInt32 m_adminCount;
    QTdInt32 m_restrictedCount;
    QTdInt32 m_bannedCount;
    bool m_canGetMembers;
    bool m_canSetUsername;
    bool m_canSetStickerSet;
    bool m_historyAvailable;
    QTdInt64 m_stickerSet;
    QString m_inviteLink;
    QTdInt64 m_pinnedMessageId;
    QTdInt32 m_upgradeGroupId;
    QTdInt64 m_upgradeMaxMsgId;
};

#endif // QTDSUPERGROUPCHAT_H
