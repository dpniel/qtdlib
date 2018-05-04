#ifndef QTDCHATACTIONFACTORY_H
#define QTDCHATACTIONFACTORY_H

#include <QObject>
#include <QJsonObject>
#include "qtdchataction.h"

class QTdChatActionFactory
{
public:
    static QTdChatAction *create(const QJsonObject &json, QObject *parent = Q_NULLPTR);
};

#endif // QTDCHATACTIONFACTORY_H
