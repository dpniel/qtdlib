#ifndef QTDTEXTFORMATTER_H
#define QTDTEXTFORMATTER_H

#include <QObject>
#include <QQuickTextDocument>
#include "messages/qtdmessagecontent.h"

class QTdTextFormatter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQuickTextDocument* textDocument READ textDocument WRITE setTextDocument NOTIFY textDocumentChanged)
    Q_PROPERTY(QTdFormattedText* content READ content WRITE setContent NOTIFY contentChanged)
    Q_PROPERTY(QColor linkColor READ linkColor WRITE setLinkColor NOTIFY linkColorChanged)
    Q_PROPERTY(QColor codeColor READ codeColor WRITE setCodeColor NOTIFY codeColorChanged)
public:
    explicit QTdTextFormatter(QObject *parent = nullptr);

    QQuickTextDocument *textDocument() const;

    QTdFormattedText *content() const;

    QColor linkColor() const;

    QColor codeColor() const;

signals:
    void textDocumentChanged(QQuickTextDocument* textDocument);
    void contentChanged(QTdFormattedText* content);

    void linkColorChanged(QColor linkColor);

    void codeColorChanged(QColor codeColor);

public slots:

    void setTextDocument(QQuickTextDocument* textDocument);

    void setContent(QTdFormattedText* content);

    void setLinkColor(QColor linkColor);

    void setCodeColor(QColor codeColor);

private slots:
    void doFormat();

private:
    QQuickTextDocument *m_textDocument;
    QTdFormattedText *m_content;
    QColor m_linkColor;
    QColor m_codeColor;
};

#endif // QTDTEXTFORMATTER_H
