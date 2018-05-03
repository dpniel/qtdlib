#ifndef QTDUSERS_H
#define QTDUSERS_H

#include <QObject>
#include <QJsonObject>
#include "user/qtduser.h"
#include "models/QmlObjectListModel.h"

class QTdUsers : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject* model READ qmlModel NOTIFY modelChanged)
public:
    explicit QTdUsers(QObject *parent = nullptr);

    static QTdUsers  *instance();

    QObject* qmlModel() const;
    QQmlObjectListModel<QTdUser> *model() const;

signals:
    void modelChanged(QObject* model);
    void userCreated(qint32 id);
public slots:

private slots:
    void handleUpdateUser(const QJsonObject &user);
    void handleUpdateUserStatus(const QString &userId, const QJsonObject &status);

private:
    QQmlObjectListModel<QTdUser> *m_model;
};

#endif // QTDUSERS_H
