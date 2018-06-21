#ifndef QTDCONNECTIONSTATEFACTORY_H
#define QTDCONNECTIONSTATEFACTORY_H

#include "qtdconnectionstate.h"
#include <QJsonObject>

struct QTdConnectionStateFactory
{
    static QTdConnectionState *create(const QJsonObject &json, QObject *parent);
};

#endif // QTDCONNECTIONSTATEFACTORY_H
