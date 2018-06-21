#include "qtdaudio.h"

QTdAudio::QTdAudio(QObject *parent) : QTdObject(parent),
    m_duration(0), m_albumCoverThumbnail(new QTdPhotoSize),
    m_audio(new QTdFile)
{
    setType(AUDIO);
}

qint32 QTdAudio::duration() const
{
    return m_duration;
}

QString QTdAudio::title() const
{
    return m_title;
}

QString QTdAudio::performer() const
{
    return m_performer;
}

QString QTdAudio::fileName() const
{
    return m_fileName;
}

QString QTdAudio::mimeType() const
{
    return m_mimeType;
}

QTdPhotoSize *QTdAudio::albumCoverThumbnail() const
{
    return m_albumCoverThumbnail.data();
}

QTdFile *QTdAudio::audio() const
{
    return m_audio.data();
}

void QTdAudio::unmarshalJson(const QJsonObject &json)
{
    m_duration = qint32(json["duration"].toInt());
    m_title = json["title"].toString();
    m_performer = json["performer"].toString();
    m_fileName = json["file_name"].toString();
    m_mimeType = json["mime_type"].toString();
    if (json.contains("album_cover_thumbnail")) {
        m_albumCoverThumbnail->unmarshalJson(json["album_cover_thumbnail"].toObject());
    }
    m_audio->unmarshalJson(json["audio"].toObject());
    emit audioChanged();
}
