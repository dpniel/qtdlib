#ifndef QTDFORMATTEDTEXT_H
#define QTDFORMATTEDTEXT_H

#include <QObject>
#include "common/qabstracttdobject.h"
#include "models/QmlObjectListModel.h"
#include "qtdtextentity.h"

class QTdFormattedText : public QTdObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text NOTIFY textChanged)
    Q_PROPERTY(QObject* entities READ qmlEntities NOTIFY entitiesChanged)
public:
    explicit QTdFormattedText(QObject *parent = nullptr);

    QString text() const;

    QQmlObjectListModel<QTdTextEntity> *entities() const;

    QObject *qmlEntities() const;

    void unmarshalJson(const QJsonObject &json);
signals:
    void textChanged();
    void entitiesChanged();

private:
    QString m_text;
    QQmlObjectListModel<QTdTextEntity> *m_entities;
};

#endif // QTDFORMATTEDTEXT_H
