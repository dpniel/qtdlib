#ifndef QTDUSERSTATUSFACTORY_H
#define QTDUSERSTATUSFACTORY_H

#include "qtduserstatus.h"

struct QTdUserStatusFactory
{
    static QTdUserStatus *create(const QJsonObject &json, QObject *parent);
};

#endif // QTDUSERSTATUSFACTORY_H
