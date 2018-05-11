#include "qtdanimation.h"

QTdAnimation::QTdAnimation(QObject *parent) : QTdObject(parent),
    m_duration(0), m_width(0), m_height(0),
    m_thumbnail(Q_NULLPTR), m_animation(Q_NULLPTR)
{
    setType(ANIMATION);
}

qint32 QTdAnimation::duration() const
{
    return m_duration;
}

qint32 QTdAnimation::width() const
{
    return m_width;
}

qint32 QTdAnimation::height() const
{
    return m_height;
}

QString QTdAnimation::fileName() const
{
    return m_fileName;
}

QString QTdAnimation::mimeType() const
{
    return m_mimeType;
}

QTdPhotoSize *QTdAnimation::thumbnail() const
{
    return m_thumbnail;
}

QTdFile *QTdAnimation::animation() const
{
    return m_animation;
}

void QTdAnimation::unmarshalJson(const QJsonObject &json)
{
    m_duration = qint32(json["duration"].toInt());
    m_width = qint32(json["width"].toInt());
    m_height = qint32(json["height"].toInt());
    m_fileName = json["file_name"].toString();
    m_mimeType = json["mime_type"].toString();
    if (json.contains("thumbnail")) {
        m_thumbnail = new QTdPhotoSize(this);
        m_thumbnail->unmarshalJson(json["thumbnail"].toObject());
    }
    m_animation = new QTdFile(this);
    m_animation->unmarshalJson(json["animation"].toObject());
    emit animationChanged();
}
