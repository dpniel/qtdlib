#ifndef QTDCHATACTION_H
#define QTDCHATACTION_H

#include <QObject>
#include "common/qabstracttdobject.h"

class QTdChatAction : public QTdObject
{
    Q_OBJECT
public:
    explicit QTdChatAction(QObject *parent = nullptr);
};

class QTdChatActionCancel : public QTdChatAction
{
    Q_OBJECT
public:
    explicit QTdChatActionCancel(QObject *parent = nullptr);
};


class QTdChatActionChoosingContact : public QTdChatAction
{
    Q_OBJECT
public:
    explicit QTdChatActionChoosingContact(QObject *parent = nullptr);
};

class QTdChatActionChoosingLocation : public QTdChatAction
{
    Q_OBJECT
public:
    explicit QTdChatActionChoosingLocation(QObject *parent = nullptr);
};

class QTdChatActionRecordingVideo : public QTdChatAction
{
    Q_OBJECT
public:
    explicit QTdChatActionRecordingVideo(QObject *parent = nullptr);
};

class QTdChatActionRecordingVideoNote : public QTdChatAction
{
    Q_OBJECT
public:
    explicit QTdChatActionRecordingVideoNote(QObject *parent = nullptr);
};

class QTdChatActionRecordingVoiceNote : public QTdChatAction
{
    Q_OBJECT
public:
    explicit QTdChatActionRecordingVoiceNote(QObject *parent = nullptr);
};

class QTdChatActionStartPlayingGame : public QTdChatAction
{
    Q_OBJECT
public:
    explicit QTdChatActionStartPlayingGame(QObject *parent = nullptr);
};

class QTdChatActionTyping : public QTdChatAction
{
    Q_OBJECT
public:
    explicit QTdChatActionTyping(QObject *parent = nullptr);
};

class QTdChatActionUploadingDocument : public QTdChatAction
{
    Q_OBJECT
public:
    explicit QTdChatActionUploadingDocument(QObject *parent = nullptr);
};

class QTdChatActionUploadingPhoto : public QTdChatAction
{
    Q_OBJECT
public:
    explicit QTdChatActionUploadingPhoto(QObject *parent = nullptr);
};

class QTdChatActionUploadingVideo : public QTdChatAction
{
    Q_OBJECT
public:
    explicit QTdChatActionUploadingVideo(QObject *parent = nullptr);
};

class QTdChatActionUploadingVideoNote : public QTdChatAction
{
    Q_OBJECT
public:
    explicit QTdChatActionUploadingVideoNote(QObject *parent = nullptr);
};

class QTdChatActionUploadingVoiceNote : public QTdChatAction
{
    Q_OBJECT
public:
    explicit QTdChatActionUploadingVoiceNote(QObject *parent = nullptr);
};

#endif // QTDCHATACTION_H
