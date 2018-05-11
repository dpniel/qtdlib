#ifndef QTDDOCUMENT_H
#define QTDDOCUMENT_H

#include <QObject>
#include "common/qabstracttdobject.h"
#include "qtdphotosize.h"

class QTdDocument : public QTdObject
{
    Q_OBJECT
    Q_PROPERTY(QString fileName READ fileName NOTIFY documentChanged)
    Q_PROPERTY(QString mimeType READ mimeType NOTIFY documentChanged)
    Q_PROPERTY(QTdPhotoSize* thumbnail READ thumbnail NOTIFY documentChanged)
    Q_PROPERTY(QTdFile* document READ document NOTIFY documentChanged)
public:
    explicit QTdDocument(QObject *parent = nullptr);

    QString fileName() const;

    QString mimeType() const;

    QTdPhotoSize *thumbnail() const;

    QTdFile *document() const;

    void unmarshalJson(const QJsonObject &json) Q_DECL_FINAL;

signals:
    void documentChanged();

private:
    QString m_fileName;
    QString m_mimeType;
    QTdPhotoSize* m_thumbnail;
    QTdFile* m_document;
};

#endif // QTDDOCUMENT_H
