#include "qtdmessage.h"
#include <QDebug>
#include "client/qtdclient.h"
#include "user/qtdusers.h"
#include "qtdmessagecontentfactory.h"


QTdMessage::QTdMessage(QObject *parent) : QAbstractInt64Id(parent),
    m_date(0), m_sender_user_id(0), m_chatId(0),
    m_sender(Q_NULLPTR), m_waitingForSender(false), m_sendingState(Q_NULLPTR),
    m_isOutgoing(false), m_canBeEdited(false), m_canBeForwarded(false),
    m_canBeDeletedOnlyForSelf(false), m_canBeDeletedForAllUsers(false),
    m_isChannelPost(false), m_containsUnreadMention(false), m_content(Q_NULLPTR),
    m_isValid(false)
{
    setType(MESSAGE);
}

QDateTime QTdMessage::qmlDate() const
{
    return QDateTime::fromTime_t(m_date);
}

qint32 QTdMessage::date() const
{
    return m_date;
}

QString QTdMessage::qmlSenderUserId() const
{
    return m_sender_user_id.toQmlValue();
}

qint32 QTdMessage::senderUserId() const
{
    return m_sender_user_id.value();
}

QString QTdMessage::qmlChatId() const
{
    return m_chatId.toQmlValue();
}

qint64 QTdMessage::chatId() const
{
    return m_chatId.value();
}

QTdUser *QTdMessage::sender() const
{
    return m_sender;
}

void QTdMessage::unmarshalJson(const QJsonObject &json)
{
    if (json.isEmpty()) {
        return;
    }
    m_isValid = false;
    m_date = qint32(json["date"].toInt());
    m_sender_user_id = json["sender_user_id"];
    if (m_sender_user_id.isValid()) {
        updateSender(m_sender_user_id.value());
    }
    m_chatId = json["chat_id"];

    updateSendingState(json);

    m_isOutgoing = json["is_outgoing"].toBool();
    m_canBeEdited = json["can_be_edited"].toBool();
    m_canBeForwarded = json["can_be_forwarded"].toBool();
    m_canBeDeletedOnlyForSelf = json["can_be_deleted_only_for_self"].toBool();
    m_canBeDeletedForAllUsers = json["can_be_deleted_for_all_users"].toBool();
    m_isChannelPost = json["is_channel_post"].toBool();
    m_containsUnreadMention = json["contains_unread_mention"].toBool();

    if (m_content) {
        m_content->deleteLater();
    }
    const QJsonObject content = json["content"].toObject();
    m_content = QTdMessageContentFactory::create(content, this);
    m_content->unmarshalJson(content);

    emit messageChanged();
    QAbstractInt64Id::unmarshalJson(json);
    m_isValid = true;
}

QTdMessageSendingState *QTdMessage::sendingState() const
{
    return m_sendingState;
}

bool QTdMessage::isOutgoing() const
{
    return m_isOutgoing;
}

bool QTdMessage::canBeEdited() const
{
    return m_canBeEdited;
}

bool QTdMessage::canBeForwarded() const
{
    return m_canBeForwarded;
}

bool QTdMessage::canBeDeletedOnlyForSelf() const
{
    return m_canBeDeletedOnlyForSelf;
}

bool QTdMessage::canBeDeletedForAllUsers() const
{
    return m_canBeDeletedForAllUsers;
}

bool QTdMessage::isChannelPost() const
{
    return m_isChannelPost;
}

bool QTdMessage::containsUnreadMention() const
{
    return m_containsUnreadMention;
}

QTdMessageContent *QTdMessage::content() const
{
    return m_content;
}

QString QTdMessage::summary() const
{
    if (!m_sender) {
        return QString();
    }
    QString name = m_sender->firstName();
    if (name.isEmpty()) {
        name = m_sender->username();
    }

    QString content;

    switch (m_content->type()) {
    case QTdMessageContent::MESSAGE_TEXT:
    {
        auto *c = qobject_cast<QTdMessageText*>(m_content);
        content = c->text()->text();
        break;
    }
    default:
        content = QStringLiteral("Sent a message");
        break;
    }

    return QString("%1: %2").arg(name, content);
}

QString QTdMessage::formatDate(const QDateTime &dt)
{
    const QDateTime now = QDateTime::currentDateTimeUtc().toLocalTime();
    const QDateTime localdt = dt.toLocalTime();
    if (now.daysTo(localdt) == 0) {
        return localdt.toString("hh:mm");
    }
    return localdt.toString("ddd hh:mm");
}

bool QTdMessage::isValid() const
{
    return m_isValid;
}

void QTdMessage::updateSender(const qint32 &senderId)
{
    if (senderId != m_sender_user_id.value()) {
        return;
    }
    if (m_sender) {
        m_sender = Q_NULLPTR;
    }

    auto *users = QTdUsers::instance()->model();
    m_sender = users->getByUid(QString::number(senderId));
    if (m_sender) {
        emit senderChanged();
        if (m_waitingForSender) {
            disconnect(QTdUsers::instance(), &QTdUsers::userCreated, this, &QTdMessage::updateSender);
            m_waitingForSender = false;
        }
        return;
    }
    connect(QTdUsers::instance(), &QTdUsers::userCreated, this, &QTdMessage::updateSender);
    QTdClient::instance()->send(QJsonObject{
                                    {"@type", "getUser"},
                                    {"user_id", m_sender_user_id.value()}
                                });
    m_waitingForSender = true;
}

void QTdMessage::updateSendingState(const QJsonObject &json)
{
    if (json.isEmpty() || !json.contains("sending_state")) {
        return;
    }

    qDebug() << "TODO: Message sending state";
}
