#ifndef QTDCHAT_H
#define QTDCHAT_H

#include <QObject>
#include <QPointer>
#include <QScopedPointer>
#include "common/qabstractint64id.h"
#include "qtdchattype.h"
#include "messages/qtdmessage.h"
#include "files/qtdphoto.h"
#include "models/QmlObjectListModel.h"
#include "notifications/qtdnotificationsettings.h"

class QTdChatPhoto : public QTdPhoto
{
    Q_OBJECT
    Q_DISABLE_COPY(QTdChatPhoto)
public:
    explicit QTdChatPhoto(QObject *parent = Q_NULLPTR);
};

/**
 * @brief The QTdChat class
 *
 * https://core.telegram.org/tdlib/docs/classtd_1_1td__api_1_1chat.html
 *
 * Some extensions have been made to this class to include the messages
 * model for the chat on each instance.
 */
class QTdChat : public QAbstractInt64Id
{
    Q_OBJECT
    Q_PROPERTY(QTdChatType* chatType READ chatType NOTIFY chatTypeChanged)
    Q_PROPERTY(QString title READ title NOTIFY titleChanged)
    Q_PROPERTY(QTdChatPhoto* chatPhoto READ chatPhoto NOTIFY chatPhotoChanged)
    Q_PROPERTY(QTdMessage* lastMessage READ lastMessage NOTIFY lastMessageChanged)
    Q_PROPERTY(QString order READ qmlOrder NOTIFY orderChanged)
    Q_PROPERTY(bool isPinned READ isPinned NOTIFY isPinnedChanged)
    Q_PROPERTY(bool canBeReported READ canBeReported NOTIFY canBeReportedChanged)
    Q_PROPERTY(bool hasUnreadMessages READ hasUnreadMessages NOTIFY unreadCountChanged)
    Q_PROPERTY(QString unreadCount READ qmlUnreadCount NOTIFY unreadCountChanged)
    Q_PROPERTY(QString lastReadInboxMessageId READ qmlLastReadInboxMessageId NOTIFY lastReadInboxMessageIdChanged)
    Q_PROPERTY(QString lastReadOutboxMessageId READ qmlLastReadOutboxMessageId NOTIFY lastReadOutboxMessageIdChanged)
    Q_PROPERTY(bool hasUnreadMentions READ hasUnreadMentions NOTIFY unreadMentionCountChanged)
    Q_PROPERTY(QString unreadMentionCount READ qmlUnreadMentionCount NOTIFY unreadMentionCountChanged)
    Q_PROPERTY(QTdNotificationSettings* notificationSettings READ notificationSettings NOTIFY notificationSettingsChanged)
    Q_PROPERTY(QString summary READ summary NOTIFY summaryChanged)
    // TODO:
    // int64:reply_markup_message_id
    // draftMessage:draf_message && updateChatDraftMessage
    // string:client_data
    Q_PROPERTY(QObject* messages READ messages NOTIFY messagesChanged)

public:
    explicit QTdChat(QObject *parent = nullptr);
    void unmarshalJson(const QJsonObject &json);
    /**
     * @brief Type of the chat
     */
    QTdChatType *chatType() const;
    /**
     * @brief Chat title
     */
    QString title() const;
    /**
     * @brief Last message in the chat,
     * @return QTdMessage* or NULL
     */
    QTdMessage *lastMessage() const;
    /**
     * @brief Chat photo
     * @return QTdChatPhoto* or NULL
     */
    QTdChatPhoto *chatPhoto() const;
    /**
     * @brief QML representation of the position in the chat list
     * \see order()
     */
    QString qmlOrder() const;
    /**
     * @brief Descending parameter by which chats are sorted.
     *
     * They must be sorted in descending order by ID.
     */
    qint64 order() const;
    /**
     * @brief True if chat is pinned
     */
    bool isPinned() const;
    /**
     * @brief True if the chat can be reported to Telegram mods
     *
     * Reports can be made through QTdReportChatRequest
     */
    bool canBeReported() const;
    /**
     * @brief Chat has unread messages
     */
    bool hasUnreadMessages() const;
    /**
     * @brief String representation of Unread count for qml
     */
    QString qmlUnreadCount() const;
    /**
     * @brief Number of unread messages in the chat
     */
    qint32 unreadCount() const;
    /**
     * @brief Identifier of last read incoming message for qml
     */
    QString qmlLastReadInboxMessageId() const;
    /**
     * @brief Identifier of last read incoming message
     */
    qint64 lastReadInboxMessageId() const;

    /**
     * @brief Identifier of last read outgoing message for qml
     */
    QString qmlLastReadOutboxMessageId() const;
    /**
     * @brief Identifier of last read outgoing message
     */
    qint64 lastReadOutboxMessageId() const;
    /**
     * @brief Chat has unread mentions
     */
    bool hasUnreadMentions() const;
    /**
     * @brief Number of unread mentions for qml
     */
    QString qmlUnreadMentionCount() const;
    /**
     * @brief Number of unread mentions
     */
    qint32 unreadMentionCount() const;
    /**
     * @brief Notification settings for this chat
     */
    QTdNotificationSettings *notificationSettings() const;

    /**
     * @brief Summary of current chat state in the UI
     *
     * This can be used to show a snippet of last message
     * or "User is typing..." type messages.
     */
    virtual QString summary() const;

    /**
     * @brief Message model
     */
    QObject *messages() const;

    /**
     * @brief Open chat
     *
     * This method should be called if the chat is opened by the user.
     * Many useful activities depend on the chat being opened or closed
     * (e.g., in supergroups and channels all updates are received only for opened chats).
     */
    Q_INVOKABLE void openChat();

    /**
     * @brief Close chat
     *
     * This method should be called if the chat is closed by the user.
     * Many useful activities depend on the chat being opened or closed
     */
    Q_INVOKABLE void closeChat();

    /**
     * @brief Pin a chat
     */
    Q_INVOKABLE void pinChat();

    /**
     * @brief Unpin chat
     */
    Q_INVOKABLE void unpinChat();

    /**
     * @brief Set chat title
     */
    Q_INVOKABLE void setTitle(const QString &title);

    QJsonObject lastMessageJson() const {
        return m_lastMsgJson;
    }

signals:
    void chatTypeChanged(QTdChatType *chatType);
    void titleChanged(QString title);
    void lastMessageChanged(QTdMessage *lastMessage);
    void chatPhotoChanged(QTdChatPhoto *chatPhoto);
    void orderChanged();
    void isPinnedChanged();
    void canBeReportedChanged();
    void unreadCountChanged();
    void lastReadInboxMessageIdChanged();
    void lastReadOutboxMessageIdChanged();
    void unreadMentionCountChanged();
    void notificationSettingsChanged();
    void messagesChanged();
    void chatStatusChanged();
    void pinChatAction(qint64 chatId, bool pinned);
    void summaryChanged();
    void closed();

public slots:
    void updateChatOrder(const QJsonObject &json);
    void updateChatReadInbox(const QJsonObject &json);
    void updateChatReadOutbox(const QJsonObject &json);
    void updateChatIsPinned(const QJsonObject &json);
    void updateChatPhoto(const QJsonObject &photo);
    void updateChatReplyMarkup(const QJsonObject &json);
    void updateChatTitle(const QJsonObject &json);
    void updateChatUnreadMentionCount(const QJsonObject &json);
    void updateLastMessage(const QJsonObject &json);
    void handleUpdateChatAction(const QJsonObject &json);

protected:
    virtual void onChatOpened();
    virtual void onChatClosed();
    virtual void updateChatAction(const QJsonObject &json);
    QPointer<QQmlObjectListModel<QTdMessage>> m_messages;

private:
    Q_DISABLE_COPY(QTdChat)
    QPointer<QTdChatType> m_chatType;
    QString m_title;
    QScopedPointer<QTdMessage> m_lastMessage;
    QScopedPointer<QTdChatPhoto> m_chatPhoto;
    QTdInt64 m_order;
    bool m_isPinned;
    bool m_canBeReported;
    QTdInt32 m_unreadCount;
    QTdInt64 m_lastReadInboxMsg;
    QTdInt64 m_lastReadOutboxMsg;
    QTdInt32 m_unreadMentionCount;
    QScopedPointer<QTdNotificationSettings> m_notifySettings;

    struct useraction {
        QTdInt32 userId;
        QString description;
        useraction(){}
        useraction(const qint32 id, const QString desc) : userId(id), description(desc) {}
    };

    QMap<qint32, useraction> m_chatActions;
    QJsonObject m_lastMsgJson;
};

#endif // QTDCHAT_H
