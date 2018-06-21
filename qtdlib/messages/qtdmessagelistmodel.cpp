#include "qtdmessagelistmodel.h"
#include <QDebug>
#include <QJsonArray>
#include "client/qtdclient.h"

QTdMessageListModel::QTdMessageListModel(QObject *parent) : QObject(parent),
    m_model(Q_NULLPTR), m_chat(Q_NULLPTR)
{
    m_model = new QQmlObjectListModel<QTdMessage>(this, "", "id");
    connect(QTdClient::instance(), &QTdClient::messages, this, &QTdMessageListModel::handleMessages);
    connect(QTdClient::instance(), &QTdClient::updateChatLastMessage, this, &QTdMessageListModel::handleUpdateChatLastMessage);
}

QTdChat *QTdMessageListModel::chat() const
{
    return m_chat;
}

QObject *QTdMessageListModel::qmlModel() const
{
    return m_model;
}

void QTdMessageListModel::setChat(QTdChat *chat)
{
    if (m_chat == chat)
        return;
    if (m_chat) {
        disconnect(m_chat, &QTdChat::closed, this, &QTdMessageListModel::cleanUp);
    }

    if (!m_model->isEmpty()) {
        cleanUp();
    }

    m_chat = chat;

    if (!m_chat) {
        return;
    }

    if (m_chat) {
        auto *m = new QTdMessage();
        m->unmarshalJson(m_chat->lastMessageJson());
        m_model->append(m);
        connect(m_chat, &QTdChat::closed, this, &QTdMessageListModel::cleanUp);
        loadMessages(m_model->first()->jsonId());
    }
    m_chat->openChat();
    emit chatChanged(m_chat);
}

void QTdMessageListModel::loadMore()
{
    if (!m_chat) {
        return;
    }
    loadMessages(m_model->last()->jsonId());
}

void QTdMessageListModel::cleanUp()
{
    qDebug() << "Cleaning up msglistmodel";
    if (m_model->isEmpty()) {
        qDebug() << "Already empty";
        return;
    }
    m_model->clear();
    qDebug() << "Messagelistmodel now at count: " << m_model->count();
}

void QTdMessageListModel::handleMessages(const QJsonObject &json)
{
    QJsonArray messages = json["messages"].toArray();
    for (const QJsonValue &msgData : messages) {
        const QJsonObject data = msgData.toObject();
        const qint64 mid = qint64(data["id"].toDouble());
        auto *msg = m_model->getByUid(QString::number(mid));
        if (!msg) {
            auto *message = new QTdMessage;
            message->unmarshalJson(data);
            m_model->append(message);
        }
    }
}

void QTdMessageListModel::handleUpdateChatLastMessage(const QJsonObject &json)
{
    if (!m_chat || json.isEmpty()) {
        return;
    }
    const qint64 id = qint64(json["chat_id"].toDouble());
    if (id != m_chat->id()) {
        return;
    }

    const QJsonObject message = json["last_message"].toObject();
    const qint64 mid = qint64(message["id"].toDouble());
    auto *msg = m_model->getByUid(QString::number(mid));
    if (msg) {
        msg->unmarshalJson(message);
        return;
    }

    auto *m = new QTdMessage();
    m->unmarshalJson(message);
    m_model->prepend(m);
}

void QTdMessageListModel::loadMessages(const QJsonValue &fromMsgId)
{
    QTdClient::instance()->send(QJsonObject{
                                    {"@type", "getChatHistory"},
                                    {"chat_id", m_chat->jsonId()},
                                    {"from_message_id", fromMsgId},
                                    {"offset", 0},
                                    {"limit", 100},
                                    {"only_local", false},
                                });
}
