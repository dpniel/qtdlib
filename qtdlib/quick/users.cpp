#include "users.h"
#include <QDebug>
#include "user/qtdusers.h"

Users::Users(QObject *parent) : QObject(parent)
{
    emit modelChanged();
}

QObject *Users::model() const
{
    return QTdUsers::instance()->model();
}
