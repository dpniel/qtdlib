#ifndef QTDSECRETCHATSTATE_H
#define QTDSECRETCHATSTATE_H

#include <QObject>
#include "common/qabstracttdobject.h"

class QTdSecretChatState : public QTdObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QTdSecretChatState)
public:
    explicit QTdSecretChatState(QObject *parent = nullptr);
};

class QTdSecretChatStateClosed : public QTdSecretChatState
{
    Q_OBJECT
    Q_DISABLE_COPY(QTdSecretChatStateClosed)
public:
    explicit QTdSecretChatStateClosed(QObject *parent = nullptr);
};

class QTdSecretChatStatePending : public QTdSecretChatState
{
    Q_OBJECT
    Q_DISABLE_COPY(QTdSecretChatStatePending)
public:
    explicit QTdSecretChatStatePending(QObject *parent = nullptr);
};

class QTdSecretChatStateReady : public QTdSecretChatState
{
    Q_OBJECT
    Q_DISABLE_COPY(QTdSecretChatStateReady)
public:
    explicit QTdSecretChatStateReady(QObject *parent = nullptr);
};

#endif // QTDSECRETCHATSTATE_H
