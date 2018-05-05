#include "qtdformattedtext.h"

QTdFormattedText::QTdFormattedText(QObject *parent) : QAbstractTdObject(parent)
{
    setType(FORMATTED_TEXT);
}

QString QTdFormattedText::text() const
{
    return m_text;
}

void QTdFormattedText::unmarshalJson(const QJsonObject &json)
{
    m_text = json["text"].toString();
}
