#ifndef QTDPHOTOSIZE_H
#define QTDPHOTOSIZE_H

#include <QObject>
#include <QScopedPointer>
#include "common/qabstracttdobject.h"
#include "qtdfile.h"

class QTdPhotoSize : public QTdObject
{
    Q_OBJECT
    Q_PROPERTY(QString type READ type NOTIFY photoSizeChanged)
    Q_PROPERTY(QTdFile* photo READ photo NOTIFY photoSizeChanged)
    Q_PROPERTY(qint32 width READ width NOTIFY photoSizeChanged)
    Q_PROPERTY(qint32 height READ height NOTIFY photoSizeChanged)
public:
    explicit QTdPhotoSize(QObject *parent = nullptr);

    QString type() const;

    QTdFile *photo() const;

    qint32 width() const;

    qint32 height() const;

    void unmarshalJson(const QJsonObject &json) Q_DECL_FINAL;

signals:
    void photoSizeChanged();

private:
    QString m_type;
    QScopedPointer<QTdFile> m_photo;
    qint32 m_width;
    qint32 m_height;
};

#endif // QTDPHOTOSIZE_H
