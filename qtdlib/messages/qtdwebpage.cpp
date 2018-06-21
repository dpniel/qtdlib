#include "qtdwebpage.h"

QTdWebPage::QTdWebPage(QObject *parent) : QTdObject(parent),
    m_photo(new QTdPhotos), m_embedWidth(0), m_embedheight(0),
    m_duration(0), m_animation(new QTdAnimation), m_audio(new QTdAudio),
    m_document(new QTdDocument), m_sticker(new QTdSticker), m_hasInstantView(false)
{
    setType(WEB_PAGE);
}

QString QTdWebPage::url() const
{
    return m_url;
}

QString QTdWebPage::displayUrl() const
{
    return m_displayUrl;
}

QString QTdWebPage::type() const
{
    return m_type;
}

QString QTdWebPage::siteName() const
{
    return m_siteName;
}

QString QTdWebPage::title() const
{
    return m_title;
}

QString QTdWebPage::description() const
{
    return m_description;
}

QTdPhotos *QTdWebPage::photo() const
{
    return m_photo.data();
}

QString QTdWebPage::embedUrl() const
{
    return m_embedUrl;
}

QString QTdWebPage::embedType() const
{
    return m_embedType;
}

qint32 QTdWebPage::embedWidth() const
{
    return m_embedWidth;
}

qint32 QTdWebPage::embedHeight() const
{
    return m_embedheight;
}

qint32 QTdWebPage::duration() const
{
    return m_duration;
}

QString QTdWebPage::author() const
{
    return m_author;
}

QTdAnimation *QTdWebPage::animation() const
{
    return m_animation.data();
}

QTdAudio *QTdWebPage::audio() const
{
    return m_audio.data();
}

QTdDocument *QTdWebPage::document() const
{
    return m_document.data();
}

QTdSticker *QTdWebPage::sticker() const
{
    return m_sticker.data();
}

bool QTdWebPage::hasInstantView() const
{
    return m_hasInstantView;
}

void QTdWebPage::unmarshalJson(const QJsonObject &json)
{
    m_url = json["url"].toString();
    m_displayUrl = json["display_url"].toString();
    m_type = json["type"].toString();
    m_siteName = json["site_name"].toString();
    m_title = json["title"].toString();
    m_description = json["description"].toString();
    if (json.contains("photo")) {
        m_photo->unmarshalJson(json["photo"].toObject());
    }
    m_embedUrl = json["embed_url"].toString();
    m_embedType = json["embed_type"].toString();
    m_embedWidth = qint32(json["embed_width"].toInt());
    m_embedheight = qint32(json["embed_height"].toInt());
    m_duration = qint32(json["duration"].toInt());
    m_author = json["author"].toString();

    if (json.contains("animation")) {
        m_animation->unmarshalJson(json["animation"].toObject());
    }

    if (json.contains("audio")) {
        m_audio->unmarshalJson(json["audio"].toObject());
    }

    if (json.contains("document")) {
        m_document->unmarshalJson(json["document"].toObject());
    }

    if (json.contains("sticker")) {
        m_sticker->unmarshalJson(json["sticker"].toObject());
    }

    m_hasInstantView = json["has_instant_preview"].toBool();
    emit webPageChanged();
}
