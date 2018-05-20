#include "qtdphoto.h"
#include "qtdlocalfile.h"
#include "qtdremotefile.h"

QTdPhoto::QTdPhoto(QObject *parent) : QAbstractInt64Id(parent),
    m_small(0), m_big(0)
{
}

QTdFile *QTdPhoto::small() const
{
    return m_small;
}

QTdFile *QTdPhoto::big() const
{
    return m_big;
}

void QTdPhoto::unmarshalJson(const QJsonObject &json)
{
    if (m_small) {
        m_small->deleteLater();
    }
    m_small = new QTdFile(this);
    m_small->unmarshalJson(json["small"].toObject());
    emit smallChanged(m_small);
    if (m_big) {
        m_big->deleteLater();
    }
    m_big = new QTdFile(this);
    m_big->unmarshalJson(json["big"].toObject());
    emit bigChanged(m_big);
    QAbstractInt64Id::unmarshalJson(json);
}
