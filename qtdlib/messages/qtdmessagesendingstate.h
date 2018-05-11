#ifndef QTDMESSAGESENDINGSTATE_H
#define QTDMESSAGESENDINGSTATE_H

#include <QObject>
#include "common/qabstracttdobject.h"

class QTdMessageSendingState : public QTdObject
{
    Q_OBJECT
public:
    explicit QTdMessageSendingState(QObject *parent = nullptr);
};

class QTdMessageSendingStateFailed : public QTdMessageSendingState
{
    Q_OBJECT
public:
    explicit QTdMessageSendingStateFailed(QObject *parent = nullptr);
};


class QTdMessageSendingStatePending : public QTdMessageSendingState
{
    Q_OBJECT
public:
    explicit QTdMessageSendingStatePending(QObject *parent = nullptr);
};
#endif // QTDMESSAGESENDINGSTATE_H
