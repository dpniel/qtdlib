#include "qtdtextentity.h"

QTdTextEntity::QTdTextEntity(QObject *parent) : QTdObject(parent),
    m_offset(0), m_length(0), m_type(Q_NULLPTR)
{
    setType(TEXT_ENTITY);
}

qint32 QTdTextEntity::offset() const
{
    return m_offset;
}

qint32 QTdTextEntity::length() const
{
    return m_length;
}

QTdTextEntityType *QTdTextEntity::entityType() const
{
    return m_type;
}

void QTdTextEntity::unmarshalJson(const QJsonObject &json)
{
    m_offset = qint32(json["offset"].toInt());
    m_length = qint32(json["length"].toInt());
    m_type = QTdTextEntityFactory::create(json["type"].toObject(), this);
    emit entityChanged();
}
