#include "qabstractint53id.h"

QAbstractInt53Id::QAbstractInt53Id(QObject *parent) : QTdObject(parent)
{

}

qint64 QAbstractInt53Id::id() const
{
    return m_id.value();
}

QString QAbstractInt53Id::qmlId() const
{
    return m_id.toQmlValue();
}

QJsonValue QAbstractInt53Id::jsonId() const
{
    return m_id.toJsonValue();
}

void QAbstractInt53Id::unmarshalJson(const QJsonObject &json)
{
    if (json.contains("id")) {
        m_id = json["id"];
    }
    QTdObject::unmarshalJson(json);
}

QAbstractInt53Id *QAbstractInt53Id::create(const QJsonObject &json, QObject *parent)
{
    auto *obj = new QAbstractInt53Id(parent);
    obj->unmarshalJson(json);
    return obj;
}
