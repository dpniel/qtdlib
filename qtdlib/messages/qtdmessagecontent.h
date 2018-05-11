#ifndef QTDMESSAGECONTENT_H
#define QTDMESSAGECONTENT_H

#include <QObject>
#include "common/qabstracttdobject.h"
#include "qtdformattedtext.h"
#include "qtdwebpage.h"

class QTdMessageContent : public QTdObject
{
    Q_OBJECT
public:
    explicit QTdMessageContent(QObject *parent = nullptr);
};

class QTdMessageText : public QTdMessageContent
{
    Q_OBJECT
    Q_PROPERTY(QTdFormattedText* text READ text NOTIFY dataChanged)
    Q_PROPERTY(QTdWebPage* webPage READ webPage NOTIFY dataChanged)
public:
    explicit QTdMessageText(QObject *parent = nullptr);

    QTdFormattedText *text() const;
    QTdWebPage *webPage() const;

    void unmarshalJson(const QJsonObject &json);

signals:
    void dataChanged();
private:
    QTdFormattedText* m_text;
    QTdWebPage* m_webPage;
};

#endif // QTDMESSAGECONTENT_H
