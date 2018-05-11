#include "qtddocument.h"

QTdDocument::QTdDocument(QObject *parent) : QTdObject(parent),
    m_thumbnail(Q_NULLPTR), m_document(Q_NULLPTR)
{
    setType(DOCUMENT);
}

QString QTdDocument::fileName() const
{
    return m_fileName;
}

QString QTdDocument::mimeType() const
{
    return m_mimeType;
}

QTdPhotoSize *QTdDocument::thumbnail() const
{
    return m_thumbnail;
}

QTdFile *QTdDocument::document() const
{
    return m_document;
}

void QTdDocument::unmarshalJson(const QJsonObject &json)
{
    m_fileName = json["file_name"].toString();
    m_mimeType = json["mime_type"].toString();
    if (json.contains("thumbnail")) {
        m_thumbnail = new QTdPhotoSize(this);
        m_thumbnail->unmarshalJson(json["thumbnail"].toObject());
    }
    m_document = new QTdFile(this);
    m_document->unmarshalJson(json["document"].toObject());
    emit documentChanged();
}
