#ifndef QTDLINKSTATEFACTORY_H
#define QTDLINKSTATEFACTORY_H

#include "qtdlinkstate.h"

struct QTdLinkStateFactory
{
    static QTdLinkState *create(const QJsonObject &json, QObject *parent);
};

#endif // QTDLINKSTATEFACTORY_H
