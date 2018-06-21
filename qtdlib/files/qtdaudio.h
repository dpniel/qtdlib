#ifndef QTDAUDIO_H
#define QTDAUDIO_H

#include <QObject>
#include <QScopedPointer>
#include "common/qabstracttdobject.h"
#include "qtdphotosize.h"


class QTdAudio : public QTdObject
{
    Q_OBJECT
    Q_PROPERTY(qint32 duration READ duration NOTIFY audioChanged)
    Q_PROPERTY(QString title READ title NOTIFY audioChanged)
    Q_PROPERTY(QString performer READ performer NOTIFY audioChanged)
    Q_PROPERTY(QString fileName READ fileName NOTIFY audioChanged)
    Q_PROPERTY(QString mimeType READ mimeType NOTIFY audioChanged)
    Q_PROPERTY(QTdPhotoSize* albumCoverThumbnail READ albumCoverThumbnail NOTIFY audioChanged)
    Q_PROPERTY(QTdFile* audio READ audio NOTIFY audioChanged)
public:
    explicit QTdAudio(QObject *parent = nullptr);

    qint32 duration() const;

    QString title() const;

    QString performer() const;

    QString fileName() const;

    QString mimeType() const;

    QTdPhotoSize *albumCoverThumbnail() const;

    QTdFile *audio() const;

    void unmarshalJson(const QJsonObject &json);

signals:
    void audioChanged();

private:
    qint32 m_duration;
    QString m_title;
    QString m_performer;
    QString m_fileName;
    QString m_mimeType;
    QScopedPointer<QTdPhotoSize> m_albumCoverThumbnail;
    QScopedPointer<QTdFile> m_audio;
};

#endif // QTDAUDIO_H
