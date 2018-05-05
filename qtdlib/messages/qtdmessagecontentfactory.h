#ifndef QTDMESSAGECONTENTFACTORY_H
#define QTDMESSAGECONTENTFACTORY_H

#include "qtdmessagecontent.h"

class QTdMessageContentFactory
{
public:
    static QTdMessageContent *create(const QJsonObject &json, QObject *parent = Q_NULLPTR);
};

#endif // QTDMESSAGECONTENTFACTORY_H
