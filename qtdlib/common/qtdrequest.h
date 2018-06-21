#ifndef QTDREQUEST_H
#define QTDREQUEST_H

#include <QObject>
#include "qabstracttdobject.h"

class QTdRequest : public QTdObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QTdRequest)
public:
    explicit QTdRequest(QObject *parent = nullptr);
};

#endif // QTDREQUEST_H
