#include "qtdchat.h"
#include <QDebug>
#include "qtdchattypefactory.h"
#include "qtdchatactionfactory.h"
#include "client/qtdclient.h"
#include "chat/requests/qtdopenchatrequest.h"
#include "chat/requests/qtdclosechatrequest.h"
#include "chat/requests/qtdsetchattitlerequest.h"
#include "user/qtdusers.h"

QTdChat::QTdChat(QObject *parent) : QAbstractInt64Id(parent),
    m_chatType(0), m_chatPhoto(new QTdChatPhoto), m_lastMessage(new QTdMessage),
    m_order(0), m_isPinned(false), m_canBeReported(false),
    m_unreadCount(0), m_lastReadInboxMsg(0), m_lastReadOutboxMsg(0),
    m_unreadMentionCount(0), m_notifySettings(new QTdNotificationSettings),
    m_messages(0)
{
    setType(CHAT);
    m_messages = new QQmlObjectListModel<QTdMessage>(this, "", "id");
    connect(QTdClient::instance(), &QTdClient::updateUserChatAction, this, &QTdChat::handleUpdateChatAction);
    emit messagesChanged();
}

void QTdChat::unmarshalJson(const QJsonObject &json)
{
    updateChatTitle(json);

    if (m_chatType) {
        m_chatType->deleteLater();
    }
    m_chatType = QTdChatFactory::createType(json["type"].toObject(), this);
    emit chatTypeChanged(m_chatType);

    updateChatPhoto(json["photo"].toObject());
    updateLastMessage(json["last_message"].toObject());

    updateChatOrder(json);
    updateChatIsPinned(json);

    m_canBeReported = json["can_be_reported"].toBool();
    emit canBeReportedChanged();

    updateChatReadInbox(json);

    updateChatReadOutbox(json);

    updateChatUnreadMentionCount(json);

    m_notifySettings->unmarshalJson(json["notification_settings"].toObject());
    emit notificationSettingsChanged();

    QAbstractInt64Id::unmarshalJson(json);
}

QString QTdChat::title() const
{
    return m_title;
}

QTdMessage *QTdChat::lastMessage() const
{
    return m_lastMessage.data();
}

QTdChatPhoto *QTdChat::chatPhoto() const
{
    return m_chatPhoto.data();
}

QString QTdChat::qmlOrder() const
{
    return m_order.toQmlValue();
}

qint64 QTdChat::order() const
{
    return m_order.value();
}

bool QTdChat::isPinned() const
{
    return m_isPinned;
}

bool QTdChat::canBeReported() const
{
    return m_canBeReported;
}

bool QTdChat::hasUnreadMessages() const
{
    return unreadCount() > 0;
}

QString QTdChat::qmlUnreadCount() const
{
    return m_unreadCount.toQmlValue();
}

qint32 QTdChat::unreadCount() const
{
    return m_unreadCount.value();
}

QString QTdChat::qmlLastReadInboxMessageId() const
{
    return m_lastReadInboxMsg.toQmlValue();
}

qint64 QTdChat::lastReadInboxMessageId() const
{
    return m_lastReadInboxMsg.value();
}

QString QTdChat::qmlLastReadOutboxMessageId() const
{
    return m_lastReadOutboxMsg.toQmlValue();
}

qint64 QTdChat::lastReadOutboxMessageId() const
{
    return m_lastReadOutboxMsg.value();
}

bool QTdChat::hasUnreadMentions() const
{
    return unreadMentionCount() > 0;
}

QString QTdChat::qmlUnreadMentionCount() const
{
    return m_unreadMentionCount.toQmlValue();
}

qint32 QTdChat::unreadMentionCount() const
{
    return m_unreadMentionCount.value();
}

QTdNotificationSettings *QTdChat::notificationSettings() const
{
    return m_notifySettings.data();
}

QString QTdChat::summary() const
{
    if (!m_chatActions.isEmpty()) {
        auto *users = QTdUsers::instance()->model();
        auto *user = users->getByUid(QString::number(m_chatActions.first().userId.value()));
        if (user) {
            return QString("%1 %2").arg(user->firstName(), m_chatActions.first().description);
        }
        // TODO: get user
        return QStringLiteral("User not available");
    }
    return m_lastMessage->isValid() ? m_lastMessage->summary() : QString();
}

QObject *QTdChat::messages() const
{
    return m_messages;
}

void QTdChat::openChat()
{
    auto *req = new QTdOpenChatRequest;
    req->setChatId(id());
    QTdClient::instance()->send(req);
    onChatOpened();
}

void QTdChat::closeChat()
{
    auto *req = new QTdCloseChatRequest;
    req->setChatId(id());
    QTdClient::instance()->send(req);
    emit closed();
}

void QTdChat::pinChat()
{
    if (!m_isPinned) {
        emit pinChatAction(id(), true);
    }
}

void QTdChat::unpinChat()
{
    if (m_isPinned) {
        emit pinChatAction(id(), false);
    }
}

void QTdChat::setTitle(const QString &title)
{
    if (m_title != title) {
        auto *req = new QTdSetChatTitleRequest;
        req->setTitle(id(), title);
        QTdClient::instance()->send(req);
    }
}

void QTdChat::updateChatOrder(const QJsonObject &json)
{
    m_order = json["order"];
    emit orderChanged();
}

void QTdChat::updateChatReadInbox(const QJsonObject &json)
{
    m_unreadCount = json["unread_count"];
    emit unreadCountChanged();

    m_lastReadInboxMsg = json["last_read_inbox_message_id"];
    emit lastReadInboxMessageIdChanged();
}

void QTdChat::updateChatReadOutbox(const QJsonObject &json)
{
    m_lastReadOutboxMsg = json["last_read_outbox_message_id"];
    emit lastReadOutboxMessageIdChanged();
}

void QTdChat::updateChatIsPinned(const QJsonObject &json)
{
    m_isPinned = json["is_pinned"].toBool();
    emit isPinnedChanged();
    updateChatOrder(json);
}

void QTdChat::updateChatPhoto(const QJsonObject &photo)
{
    m_chatPhoto->unmarshalJson(photo);
    emit chatPhotoChanged(m_chatPhoto.data());

    if (m_chatPhoto->small()->local()->path().isEmpty()) {
        m_chatPhoto->small()->downloadFile();
    }
}

void QTdChat::updateChatReplyMarkup(const QJsonObject &json)
{
//    https://core.telegram.org/tdlib/docs/classtd_1_1td__api_1_1update_chat_reply_markup.html
    Q_UNUSED(json);
    qWarning() << __func__ << "NOT IMPLEMENTED";
}

void QTdChat::updateChatTitle(const QJsonObject &json)
{
    m_title = json["title"].toString();
    emit titleChanged(m_title);
}

void QTdChat::updateChatUnreadMentionCount(const QJsonObject &json)
{
    m_unreadMentionCount = json["unread_mention_count"];
    emit unreadMentionCountChanged();
}

void QTdChat::updateLastMessage(const QJsonObject &json)
{
    if (json.isEmpty()) {
        return;
    }

    m_lastMsgJson = json["last_message"].toObject();
    m_lastMessage->unmarshalJson(m_lastMsgJson);
    emit lastMessageChanged(m_lastMessage.data());
    emit summaryChanged();
}

void QTdChat::handleUpdateChatAction(const QJsonObject &json)
{
    const qint64 cid = qint64(json["chat_id"].toDouble());
    if (cid != id()) {
        return;
    }
    updateChatAction(json);
}

void QTdChat::onChatOpened()
{
    // Do nothing here;
}

void QTdChat::onChatClosed()
{
    // Do nothing here;
}

void QTdChat::updateChatAction(const QJsonObject &json)
{
    const qint32 user_id = qint32(json["user_id"].toInt());
    const QJsonObject data = json["action"].toObject();
    QTdChatAction *action = QTdChatActionFactory::create(data, this);
    if (action->type() == QTdChatAction::Type::CHAT_ACTION_CANCEL && m_chatActions.contains(user_id)) {
        m_chatActions.remove(user_id);
    } else if (action->type() != QTdChatAction::Type::CHAT_ACTION_CANCEL && !m_chatActions.contains(user_id)) {
        QString description;
        // TODO: i18n these strings
        switch (action->type()) {
        case QTdChatAction::Type::CHAT_ACTION_CANCEL:
            return;
        case QTdChatAction::Type::CHAT_ACTION_CHOOSING_CONTACT:
            description = QStringLiteral("is choosing contact...");
            break;
        case QTdChatAction::Type::CHAT_ACTION_CHOOSING_LOCATION:
            description = QStringLiteral("is choosing location...");
            break;
        case QTdChatAction::Type::CHAT_ACTION_RECORDING_VIDEO:
        case QTdChatAction::Type::CHAT_ACTION_RECORDING_VIDEO_NOTE:
        case QTdChatAction::Type::CHAT_ACTION_RECORDING_VOICE_NOTE:
            description = QStringLiteral("is recording...");
            break;
        case QTdChatAction::Type::CHAT_ACTION_TYPING:
            description = QStringLiteral("is typing...");
            break;
        default:
            description = QStringLiteral("Is doing something");
            break;
        }
        m_chatActions.insert(user_id, useraction(user_id, description));
    }
    action->deleteLater();
    emit summaryChanged();
}

QTdChatType *QTdChat::chatType() const
{
    return m_chatType;
}

QTdChatPhoto::QTdChatPhoto(QObject *parent) : QTdPhoto(parent)
{
    setType(CHAT_PHOTO);
}
