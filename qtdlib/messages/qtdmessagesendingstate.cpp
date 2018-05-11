#include "qtdmessagesendingstate.h"

QTdMessageSendingState::QTdMessageSendingState(QObject *parent) : QTdObject(parent)
{
}

QTdMessageSendingStateFailed::QTdMessageSendingStateFailed(QObject *parent) : QTdMessageSendingState(parent)
{
    setType(MESSAGE_SENDING_STATE_FAILED);
}

QTdMessageSendingStatePending::QTdMessageSendingStatePending(QObject *parent) : QTdMessageSendingState(parent)
{
    setType(MESSAGE_SENDING_STATE_PENDING);
}
