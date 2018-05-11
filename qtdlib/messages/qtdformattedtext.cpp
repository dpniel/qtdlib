#include "qtdformattedtext.h"
#include <QJsonArray>

QTdFormattedText::QTdFormattedText(QObject *parent) : QTdObject(parent),
    m_entities(Q_NULLPTR)
{
    setType(FORMATTED_TEXT);
    m_entities = new QQmlObjectListModel<QTdTextEntity>(this);
}

QString QTdFormattedText::text() const
{
    return m_text;
}

QQmlObjectListModel<QTdTextEntity> *QTdFormattedText::entities() const
{
    return m_entities;
}

QObject *QTdFormattedText::qmlEntities() const { return m_entities; }

void QTdFormattedText::unmarshalJson(const QJsonObject &json)
{
    m_text = json["text"].toString();
    emit textChanged();
    const QJsonArray entities = json["entities"].toArray();
    for (const QJsonValue &value : entities) {
        auto *entity = new QTdTextEntity();
        entity->unmarshalJson(value.toObject());
        m_entities->append(entity);
    }
    emit entitiesChanged();
}
