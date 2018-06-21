#include "qtdphotosize.h"
#include <QDebug>

QTdPhotoSize::QTdPhotoSize(QObject *parent) : QTdObject(parent),
    m_photo(new QTdFile), m_width(0), m_height(0)
{
    setType(PHOTO_SIZE);
}

QString QTdPhotoSize::type() const
{
    return m_type;
}

QTdFile *QTdPhotoSize::photo() const
{
    return m_photo.data();
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
    m_photo->unmarshalJson(json["photo"].toObject());
    if (m_photo->local()->path().isEmpty()) {
        m_photo->downloadFile();
    }
    m_width = qint32(json["width"].toInt());
    m_height = qint32(json["height"].toInt());
    emit photoSizeChanged();
}
