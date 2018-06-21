#ifndef QTDMESSAGE_H
#define QTDMESSAGE_H

#include <QObject>
#include <QPointer>
#include <QDateTime>
#include "common/qabstractint64id.h"
#include "user/qtduser.h"
#include "qtdmessagesendingstate.h"
#include "qtdmessagecontent.h"


class QTdMessage : public QAbstractInt64Id
{
    Q_OBJECT
    Q_PROPERTY(QDateTime date READ qmlDate NOTIFY messageChanged)
    Q_PROPERTY(QString senderUserId READ qmlSenderUserId NOTIFY messageChanged)
    Q_PROPERTY(QString chatId READ qmlChatId NOTIFY messageChanged)
    Q_PROPERTY(QTdMessageSendingState *sendingState READ sendingState NOTIFY sendingStateChanged)
    Q_PROPERTY(bool isOutgoing READ isOutgoing NOTIFY messageChanged)
    Q_PROPERTY(bool canBeEdited READ canBeEdited NOTIFY messageChanged)
    Q_PROPERTY(bool canBeForwarded READ canBeForwarded NOTIFY messageChanged)
    Q_PROPERTY(bool canBeDeletedOnlyForSelf READ canBeDeletedOnlyForSelf NOTIFY messageChanged)
    Q_PROPERTY(bool canBeDeletedForAllUsers READ canBeDeletedForAllUsers NOTIFY messageChanged)
    Q_PROPERTY(bool isChannelPost READ isChannelPost NOTIFY messageChanged)
    Q_PROPERTY(bool containsUnreadMention READ containsUnreadMention NOTIFY messageChanged)
    Q_PROPERTY(QTdMessageContent* content READ content NOTIFY messageChanged)
    // These aren't original properties of the tdlib message class but we can
    // can make life easier for use in QML.
    Q_PROPERTY(QTdUser *sender READ sender NOTIFY senderChanged)
    // Provide a summary text for display in the chatlist
    Q_PROPERTY(QString summary READ summary NOTIFY senderChanged)
public:
    explicit QTdMessage(QObject *parent = nullptr);

    QDateTime qmlDate() const;
    qint32 date() const;
    QString qmlSenderUserId() const;
    qint32 senderUserId() const;
    QString qmlChatId() const;
    qint64 chatId() const;

    QTdUser *sender() const;

    void unmarshalJson(const QJsonObject &json);

    QTdMessageSendingState *sendingState() const;

    bool isOutgoing() const;

    bool canBeEdited() const;

    bool canBeForwarded() const;

    bool canBeDeletedOnlyForSelf() const;

    bool canBeDeletedForAllUsers() const;

    bool isChannelPost() const;

    bool containsUnreadMention() const;

    QTdMessageContent *content() const;

    QString summary() const;

    Q_INVOKABLE QString formatDate(const QDateTime &dt);

    bool isValid() const;

signals:
    void messageChanged();
    void senderChanged();
    void sendingStateChanged();

private slots:
    void updateSender(const qint32 &senderId);
    void updateSendingState(const QJsonObject &json);

private:
    qint32 m_date;
    QTdInt32 m_sender_user_id;
    QTdInt64 m_chatId;
    QPointer<QTdUser> m_sender;
    bool m_waitingForSender;
    QPointer<QTdMessageSendingState> m_sendingState;
    bool m_isOutgoing;
    bool m_canBeEdited;
    bool m_canBeForwarded;
    bool m_canBeDeletedOnlyForSelf;
    bool m_canBeDeletedForAllUsers;
    bool m_isChannelPost;
    bool m_containsUnreadMention;
    QPointer<QTdMessageContent> m_content;
    bool m_isValid;
};

#endif // QTDMESSAGE_H
