#ifndef QTDBASICGROUPCHAT_H
#define QTDBASICGROUPCHAT_H

#include <QObject>
#include <QMap>
#include <QPointer>
#include "qtdchat.h"
#include "qtdchatmemberstatus.h"
#include "qtdchatmember.h"

class QTdBasicGroupChat : public QTdChat
{
    Q_OBJECT
    Q_PROPERTY(QString groupId READ qmlGroupId NOTIFY groupChanged)
    Q_PROPERTY(QString memberCount READ qmlMemberCount NOTIFY groupChanged)
    Q_PROPERTY(QTdChatMemberStatus* status READ status NOTIFY groupChanged)
    Q_PROPERTY(bool everyoneIsAdmin READ everyoneIsAdmin NOTIFY groupChanged)
    Q_PROPERTY(bool isActive READ isActive NOTIFY groupChanged)
    Q_PROPERTY(QString upgradedToSuperGroupId READ qmlUpgradedToSuperGroupId NOTIFY groupChanged)

    // BasicGroupFullInfo properties
    Q_PROPERTY(QString creatorUserId READ qmlCreatorUserId NOTIFY groupInfoChanged)
    Q_PROPERTY(QObject *members READ qmlMembers NOTIFY groupInfoChanged)
    Q_PROPERTY(QString inviteLink READ inviteLink NOTIFY groupInfoChanged)
public:
    explicit QTdBasicGroupChat(QObject *parent = nullptr);

    QString qmlGroupId() const;
    qint32 groupId() const;
    QString qmlMemberCount() const;
    qint32 memberCount() const;
    QTdChatMemberStatus* status() const;
    bool everyoneIsAdmin() const;
    bool isActive() const;
    QString qmlUpgradedToSuperGroupId() const;
    qint32 upgradedToSuperGroupId() const;
    QString qmlCreatorUserId() const;
    qint32 creatorUserId() const;
    QObject *qmlMembers() const;
    QQmlObjectListModel<QTdChatMember> *members() const;
    QString inviteLink() const;

signals:
    void groupChanged();
    void groupInfoChanged();

protected:
    virtual void onChatOpened();

private slots:
    void requestGroupData();
    void updateGroupData(const QJsonObject &json);
    void updateGroupInfo(const QJsonObject &json);

private:
    Q_DISABLE_COPY(QTdBasicGroupChat)
    QTdInt32 m_groupId;
    QTdInt32 m_memberCount;
    QPointer<QTdChatMemberStatus> m_status;
    bool m_everyoneIsAdmin;
    bool m_isActive;
    QTdInt32 m_upgradedSGID;
    QTdInt32 m_creatorId;
    QPointer<QQmlObjectListModel<QTdChatMember>> m_members;
    QString m_inviteLink;
};

#endif // QTDBASICGROUPCHAT_H
