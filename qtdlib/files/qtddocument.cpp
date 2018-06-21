#include "qtddocument.h"

QTdDocument::QTdDocument(QObject *parent) : QTdObject(parent),
    m_thumbnail(new QTdPhotoSize), m_document(new QTdFile)
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
    return m_thumbnail.data();
}

QTdFile *QTdDocument::document() const
{
    return m_document.data();
}

void QTdDocument::unmarshalJson(const QJsonObject &json)
{
    m_fileName = json["file_name"].toString();
    m_mimeType = json["mime_type"].toString();
    if (json.contains("thumbnail")) {
        m_thumbnail->unmarshalJson(json["thumbnail"].toObject());
    }
    m_document->unmarshalJson(json["document"].toObject());
    emit documentChanged();
}
