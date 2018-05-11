#include "qtdphotosize.h"
#include <QDebug>

QTdPhotoSize::QTdPhotoSize(QObject *parent) : QTdObject(parent),
    m_photo(Q_NULLPTR), m_width(0), m_height(0)
{
    setType(PHOTO_SIZE);
}

QString QTdPhotoSize::type() const
{
    return m_type;
}

QTdFile *QTdPhotoSize::photo() const
{
    return m_photo;
}

qint32 QTdPhotoSize::width() const
{
    return m_width;
}

qint32 QTdPhotoSize::height() const
{
    return m_height;
}

void QTdPhotoSize::unmarshalJson(const QJsonObject &json)
{
    m_type = json["type"].toString();
    m_photo = new QTdFile(this);
    m_photo->unmarshalJson(json["photo"].toObject());
    m_width = qint32(json["width"].toInt());
    m_height = qint32(json["height"].toInt());
    emit photoSizeChanged();
}
