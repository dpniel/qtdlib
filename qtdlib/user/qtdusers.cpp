#include "qtdusers.h"
#include <QPointer>
#include <QDebug>
#include "client/qtdclient.h"
#include "common/qtdint.h"
#include "user/qtduserstatusfactory.h"

QTdUsers::QTdUsers(QObject *parent) : QObject(parent),
    m_model(Q_NULLPTR)
{
    m_model = new QQmlObjectListModel<QTdUser>(this, "", "id");
    connect(QTdClient::instance(), &QTdClient::updateUser, this, &QTdUsers::handleUpdateUser);
    connect(QTdClient::instance(), &QTdClient::updateUserStatus, this, &QTdUsers::handleUpdateUserStatus);
}

QTdUsers::~QTdUsers()
{
    m_model->clear();
}

QObject *QTdUsers::qmlModel() const
{
    return m_model;
}

QQmlObjectListModel<QTdUser> *QTdUsers::model() const
{
    return m_model;
}

static QPointer<QTdUsers> s_users;
QTdUsers *QTdUsers::instance()
{
    if (s_users.isNull()) {
        s_users = new QTdUsers();
    }
    return s_users;
}

void QTdUsers::handleUpdateUser(const QJsonObject &user)
{
//    qDebug() << "[UPDATING USER]" << user;
    const qint32 uid = qint32(user["id"].toInt());
    // Need to remember the model actually indexes on the qmlId variant which is a QString
    QTdUser *tduser = m_model->getByUid(QString::number(uid));
    if (!tduser) {
//        qDebug() << "Adding new user to model";
        tduser = new QTdUser();
        tduser->unmarshalJson(user);
        m_model->append(tduser);
        emit userCreated(uid);
//        qDebug() << "USERCOUNT: " << m_model->count();
    } else {
        tduser->unmarshalJson(user);
    }
}

void QTdUsers::handleUpdateUserStatus(const QString &userId, const QJsonObject &status)
{
//    qDebug() << "[UPDATING USER STATUS]" << userId;
    QTdUser *tduser = m_model->getByUid(userId);
    if (tduser) {
//        qDebug() << "Updating existing user status: " << tduser->id();
        tduser->setStatus(QTdUserStatusFactory::create(status, tduser));
    }
}
