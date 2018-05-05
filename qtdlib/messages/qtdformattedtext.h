#ifndef QTDFORMATTEDTEXT_H
#define QTDFORMATTEDTEXT_H

#include <QObject>
#include "common/qabstracttdobject.h"

class QTdFormattedText : public QAbstractTdObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text NOTIFY textChanged)
public:
    explicit QTdFormattedText(QObject *parent = nullptr);

    QString text() const;

    void unmarshalJson(const QJsonObject &json);
signals:
    void textChanged();

private:
    QString m_text;
};

#endif // QTDFORMATTEDTEXT_H
