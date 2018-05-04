#ifndef QTDGETSUPERGROUPFULLINFOREQUEST_H
#define QTDGETSUPERGROUPFULLINFOREQUEST_H

#include <QObject>
#include "common/qtdrequest.h"

class QTdGetSuperGroupFullInfoRequest : public QTdRequest
{
    Q_OBJECT
    qint32 m_id;
public:
    explicit QTdGetSuperGroupFullInfoRequest(QObject *parent = nullptr);

    void setSupergroupId(const qint32 &id);
    QJsonObject marshalJson();
};

#endif // QTDGETSUPERGROUPFULLINFOREQUEST_H
