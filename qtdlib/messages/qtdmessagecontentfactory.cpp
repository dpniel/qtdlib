#include "qtdmessagecontentfactory.h"

QTdMessageContent *QTdMessageContentFactory::create(const QJsonObject &json, QObject *parent)
{
    const QString type = json["@type"].toString();
    if (type == "messageText") {
        return new QTdMessageText(parent);
    }
    return new QTdMessageContent(parent);
}
