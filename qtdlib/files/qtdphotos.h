#ifndef QTDPHOTOS_H
#define QTDPHOTOS_H

#include <QObject>
#include <QPointer>
#include "common/qabstractint64id.h"
#include "models/QmlObjectListModel.h"
#include "qtdphotosize.h"

class QTdPhotos : public QAbstractInt64Id
{
    Q_OBJECT
    Q_PROPERTY(bool hasSitckers READ hasStickers NOTIFY photosChanged)
    Q_PROPERTY(QObject* sizes READ qmlSizes NOTIFY photosChanged)
public:
    explicit QTdPhotos(QObject *parent = nullptr);
    ~QTdPhotos();

    void unmarshalJson(const QJsonObject &json);

    bool hasStickers() const;

    QObject *qmlSizes() const;
    QQmlObjectListModel<QTdPhotoSize> *sizes() const;

signals:
    void photosChanged();

private:
    bool m_hasStickers;
    QPointer<QQmlObjectListModel<QTdPhotoSize>> m_sizes;
    bool m_hasSitckers;
};

#endif // QTDPHOTOS_H
