#include "qtdchataction.h"

QTdChatAction::QTdChatAction(QObject *parent) : QTdObject(parent)
{
}

QTdChatActionCancel::QTdChatActionCancel(QObject *parent) : QTdChatAction(parent)
{
    setType(CHAT_ACTION_CANCEL);
}

QTdChatActionChoosingContact::QTdChatActionChoosingContact(QObject *parent) : QTdChatAction(parent)
{
    setType(CHAT_ACTION_CHOOSING_CONTACT);
}

QTdChatActionRecordingVideo::QTdChatActionRecordingVideo(QObject *parent) : QTdChatAction(parent)
{
    setType(CHAT_ACTION_RECORDING_VIDEO);
}

QTdChatActionChoosingLocation::QTdChatActionChoosingLocation(QObject *parent) : QTdChatAction(parent)
{
    setType(CHAT_ACTION_CHOOSING_LOCATION);
}

QTdChatActionRecordingVideoNote::QTdChatActionRecordingVideoNote(QObject *parent) : QTdChatAction(parent)
{
    setType(CHAT_ACTION_RECORDING_VIDEO_NOTE);
}

QTdChatActionRecordingVoiceNote::QTdChatActionRecordingVoiceNote(QObject *parent) : QTdChatAction(parent)
{
    setType(CHAT_ACTION_RECORDING_VOICE_NOTE);
}

QTdChatActionStartPlayingGame::QTdChatActionStartPlayingGame(QObject *parent) : QTdChatAction(parent)
{
    setType(CHAT_ACTION_START_PLAYING_GAME);
}

QTdChatActionTyping::QTdChatActionTyping(QObject *parent) : QTdChatAction(parent)
{
    setType(CHAT_ACTION_TYPING);
}

QTdChatActionUploadingDocument::QTdChatActionUploadingDocument(QObject *parent) : QTdChatAction(parent)
{
    setType(CHAT_ACTION_UPLOADING_DOCUMENT);
}

QTdChatActionUploadingPhoto::QTdChatActionUploadingPhoto(QObject *parent) : QTdChatAction(parent)
{
    setType(CHAT_ACTION_UPLOADING_PHOTO);
}

QTdChatActionUploadingVideo::QTdChatActionUploadingVideo(QObject *parent) : QTdChatAction(parent)
{
    setType(CHAT_ACTION_UPLOADING_VIDEO);
}

QTdChatActionUploadingVideoNote::QTdChatActionUploadingVideoNote(QObject *parent) : QTdChatAction(parent)
{
    setType(CHAT_ACTION_UPLOADING_VIDEO_NOTE);
}

QTdChatActionUploadingVoiceNote::QTdChatActionUploadingVoiceNote(QObject *parent) : QTdChatAction(parent)
{
    setType(CHAT_ACTION_UPLOADING_VOICE_NOTE);
}
