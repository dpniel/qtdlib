#ifndef QTDMESSAGECONTENTFACTORY_H
#define QTDMESSAGECONTENTFACTORY_H

#include "qtdmessagecontent.h"

struct QTdMessageContentFactory
{
    static QTdMessageContent *create(const QJsonObject &json, QObject *parent = Q_NULLPTR);
};

#endif // QTDMESSAGECONTENTFACTORY_H
