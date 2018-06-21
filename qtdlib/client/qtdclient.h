#ifndef QTDCLIENT_H
#define QTDCLIENT_H

#include <functional>
#include <QObject>
#include <QPointer>
#include <QSharedPointer>
#include <QScopedPointer>
#include <QHash>
#include <QFuture>
#include <QThread>
#include <QJsonObject>
#include "auth/qtdauthstate.h"
#include "connections/qtdconnectionstate.h"
#include "common/qtdrequest.h"

// callback to trigger on received messages from tdlib.
typedef std::function<void(QJsonObject)> ReceiveCallback;

/**
 * @brief The QTdClient class
 *
 * QTdClient is the main interface for communication with
 * the tdlib backend. A static instance is used to easily share
 * between components.
 */
class QTdClient : public QObject
{
    Q_OBJECT
public:
    explicit QTdClient(QObject *parent = nullptr);

    /**
     * @brief Shared static instance in the main thread.
     */
    static QTdClient *instance();

    /**
     * @brief The current authentication state
     */
    QTdAuthState *authState() const;
    /**
     * @brief The current connection state
     */
    QTdConnectionState *connectionState() const;

    /**
     * @brief send
     *
     * Send a request in another thread.
     *
     * QTdClient will take ownership of obj and schedule deletion once
     * it is done with it,
     */
    void send(QTdRequest *obj);
    void send(const QJsonObject &json);
    /**
     * @brief Execute synchronous request in another Thread
     *
     * This is a synchronous action in another
     * thread and will return the result via the
     * returned QFuture
     *
     * QTdClient will take ownership of obj and schedule deletion once
     * it is done with it,
     *
     * Note: there is only a limited set of actions that can be sent
     * through exec. Still need to figure out what they are. Once
     * found it will be indicated in each QTdRequest derived class
     * documentation
     */
    QFuture<QJsonObject> exec(QTdRequest *obj);
    QFuture<QJsonObject> exec(const QJsonObject &json);

signals:
    void authStateChanged(QTdAuthState *state);
    void connectionStateChanged(QTdConnectionState *state);
    void updateUser(const QJsonObject &user);
    void updateUserStatus(const QString &user_id, const QJsonObject &status);
    void updateFile(const QJsonObject &file);
    void updateNewChat(const QJsonObject &chat);
    void updateChatOrder(const QJsonObject &chat);
    void updateChatLastMessage(const QJsonObject &chat);
    void updateBasicGroup(const QJsonObject &group);
    void updateBasicGroupFullInfo(const QJsonObject &group);
    void secretChat(const QJsonObject &chat);
    void updateSecretChat(const QJsonObject &chat);
    void superGroup(const QJsonObject &group);
    void updateSuperGroup(const QJsonObject &group);
    void supergroupFullInfo(const QJsonObject &group);
    void updateSupergroupFullInfo(const QJsonObject &group);
    void updateChatReadInbox(const QJsonObject &chat);
    void updateChatReadOutbox(const QJsonObject &chat);
    void updateChatIsPinned(const QJsonObject &chat);
    void updateChatPhoto(const QJsonObject &photo);
    void updateChatReplyMarkup(const QJsonObject &chat);
    void updateChatTitle(const QJsonObject &chat);
    void updateChatUnreadMentionCount(const QJsonObject &chat);
    void updateUserChatAction(const QJsonObject &chat);
    void messages(const QJsonObject &messages);
    void updateDeleteMessages(const QJsonObject &messages);

private slots:
    void handleRecv(const QJsonObject &data);
private:
    Q_DISABLE_COPY(QTdClient)
    void init();
    QScopedPointer<QThread> m_worker;
    QPointer<QTdAuthState> m_authState;
    QPointer<QTdConnectionState> m_connectionState;
    QHash<QString, ReceiveCallback> m_events;
};

#endif // QTDCLIENT_H
