#ifndef QTDTEXTENTITY_H
#define QTDTEXTENTITY_H

#include <QObject>
#include "common/qabstracttdobject.h"
#include "qtdtextentitytype.h"

class QTdTextEntity : public QTdObject
{
    Q_OBJECT
    Q_PROPERTY(qint32 offset READ offset NOTIFY entityChanged)
    Q_PROPERTY(qint32 length READ length NOTIFY entityChanged)
    Q_PROPERTY(QTdTextEntityType* type READ type NOTIFY entityChanged)
public:
    explicit QTdTextEntity(QObject *parent = nullptr);

    qint32 offset() const;

    qint32 length() const;

    QTdTextEntityType *type() const;

    void unmarshalJson(const QJsonObject &json);

signals:
    void entityChanged();

private:
    qint32 m_offset;
    qint32 m_length;
    QTdTextEntityType* m_type;
};

#endif // QTDTEXTENTITY_H
