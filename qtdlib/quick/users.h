#ifndef USERS_H
#define USERS_H

#include <QObject>
#include <QJsonObject>

class Users : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject* model READ model NOTIFY modelChanged)
public:
    explicit Users(QObject *parent = nullptr);

    QObject* model() const;

signals:
    void modelChanged();
};

#endif // USERS_H
