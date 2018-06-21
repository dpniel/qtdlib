#ifndef QTDWEBPAGE_H
#define QTDWEBPAGE_H

#include <QObject>
#include <QScopedPointer>
#include "common/qabstracttdobject.h"
#include "files/qtdphotos.h"
#include "files/qtdanimation.h"
#include "files/qtdaudio.h"
#include "files/qtddocument.h"
#include "files/qtdsticker.h"

class QTdWebPage : public QTdObject
{
    Q_OBJECT
    Q_PROPERTY(QString url READ url NOTIFY webPageChanged)
    Q_PROPERTY(QString displayUrl READ displayUrl NOTIFY webPageChanged)
    Q_PROPERTY(QString type READ type NOTIFY webPageChanged)
    Q_PROPERTY(QString siteName READ siteName NOTIFY webPageChanged)
    Q_PROPERTY(QString title READ title NOTIFY webPageChanged)
    Q_PROPERTY(QString description READ description NOTIFY webPageChanged)
    Q_PROPERTY(QTdPhotos* photo READ photo NOTIFY webPageChanged)
    Q_PROPERTY(QString embedUrl READ embedUrl NOTIFY webPageChanged)
    Q_PROPERTY(QString embedType READ embedType NOTIFY webPageChanged)
    Q_PROPERTY(qint32 embedWidth READ embedWidth NOTIFY webPageChanged)
    Q_PROPERTY(qint32 embedheight READ embedHeight NOTIFY webPageChanged)
    Q_PROPERTY(qint32 duration READ duration NOTIFY webPageChanged)
    Q_PROPERTY(QString author READ author NOTIFY webPageChanged)
    Q_PROPERTY(QTdAnimation* animation READ animation NOTIFY webPageChanged)
    Q_PROPERTY(QTdAudio* audio READ audio NOTIFY webPageChanged)
    Q_PROPERTY(QTdDocument* document READ document NOTIFY webPageChanged)
    Q_PROPERTY(QTdSticker* sticker READ sticker NOTIFY webPageChanged)
    /**
      TODO: QTdVideo, QTdVideoNote QTdVoiceNote
     */
    Q_PROPERTY(bool hasInstantView READ hasInstantView NOTIFY webPageChanged)
public:
    explicit QTdWebPage(QObject *parent = Q_NULLPTR);

    QString url() const;

    QString displayUrl() const;

    QString type() const;

    QString siteName() const;

    QString title() const;

    QString description() const;

    QTdPhotos *photo() const;

    QString embedUrl() const;

    QString embedType() const;

    qint32 embedWidth() const;

    qint32 embedHeight() const;

    qint32 duration() const;

    QString author() const;

    QTdAnimation *animation() const;

    QTdAudio *audio() const;

    QTdDocument *document() const;

    QTdSticker *sticker() const;

    bool hasInstantView() const;

    void unmarshalJson(const QJsonObject &json) Q_DECL_FINAL;

signals:
    void webPageChanged();

private:
    QString m_url;
    QString m_displayUrl;
    QString m_type;
    QString m_siteName;
    QString m_title;
    QString m_description;
    QScopedPointer<QTdPhotos> m_photo;
    QString m_embedUrl;
    QString m_embedType;
    qint32 m_embedWidth;
    qint32 m_embedheight;
    qint32 m_duration;
    QString m_author;
    QScopedPointer<QTdAnimation> m_animation;
    QScopedPointer<QTdAudio> m_audio;
    QScopedPointer<QTdDocument> m_document;
    QScopedPointer<QTdSticker> m_sticker;
    bool m_hasInstantView;
};

#endif // QTDWEBPAGE_H
