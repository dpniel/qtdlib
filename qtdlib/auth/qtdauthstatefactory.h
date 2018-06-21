#ifndef QTDAUTHSTATEFACTORY_H
#define QTDAUTHSTATEFACTORY_H

#include "qtdauthstate.h"

struct QTdAuthStateFactory
{
    static QTdAuthState *create(const QJsonObject &data, QObject *parent);
};

#endif // QTDAUTHSTATEFACTORY_H
