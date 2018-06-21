#ifndef QTDREPORTCHATREQUEST_H
#define QTDREPORTCHATREQUEST_H

#include <QObject>

class QTdReportChatRequest : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QTdReportChatRequest)
public:
    explicit QTdReportChatRequest(QObject *parent = nullptr);
};

#endif // QTDREPORTCHATREQUEST_H
