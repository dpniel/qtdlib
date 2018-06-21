#ifndef QTDLINKSTATE_H
#define QTDLINKSTATE_H

#include <QObject>
#include "common/qabstracttdobject.h"

class QTdLinkState : public QTdObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QTdLinkState)
public:
    explicit QTdLinkState(QObject *parent = nullptr);
};

class QTdLinkStateIsContact : public QTdLinkState
{
    Q_OBJECT
    Q_DISABLE_COPY(QTdLinkStateIsContact)
public:
    explicit QTdLinkStateIsContact(QObject *parent = Q_NULLPTR);
};

class QTdLinkStateKnowsPhoneNumber : public QTdLinkState
{
    Q_OBJECT
    Q_DISABLE_COPY(QTdLinkStateKnowsPhoneNumber)
public:
    explicit QTdLinkStateKnowsPhoneNumber(QObject *parent = Q_NULLPTR);
};

class QTdLinkStateNone : public QTdLinkState
{
    Q_OBJECT
    Q_DISABLE_COPY(QTdLinkStateNone)
public:
    explicit QTdLinkStateNone(QObject *parent = Q_NULLPTR);
};

#endif // QTDLINKSTATE_H
