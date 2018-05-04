#include "qtdchatactionfactory.h"

QTdChatAction *QTdChatActionFactory::create(const QJsonObject &json, QObject *parent)
{
    const QString type = json["@type"].toString();
    if (type == "chatActionCancel") {
        return new QTdChatActionCancel(parent);
    } else if (type == "chatActionChoosingContact") {
        return new QTdChatActionChoosingContact(parent);
    } else if (type == "chatActionChoosingLocation") {
        return new QTdChatActionChoosingLocation(parent);
    } else if (type == "chatActionRecordingVideo") {
        return new QTdChatActionRecordingVideo(parent);
    } else if (type == "chatActionRecordingVideoNote") {
        return new QTdChatActionRecordingVideoNote(parent);
    } else if (type == "chatActionRecordingVoiceNote") {
        return new QTdChatActionRecordingVoiceNote(parent);
    } else if (type == "chatActionStartPlayingGame") {
        return new QTdChatActionStartPlayingGame(parent);
    } else if (type == "chatActionTyping") {
        return new QTdChatActionTyping(parent);
    } else if (type == "chatActionUploadingDocument") {
        return new QTdChatActionUploadingDocument(parent);
    } else if (type == "chatActionUploadingPhoto") {
        return new QTdChatActionUploadingPhoto(parent);
    } else if (type == "chatActionUploadingVideo") {
        return new QTdChatActionUploadingVideo(parent);
    } else if (type == "chatActionUploadingVideoNote") {
        return new QTdChatActionUploadingVideoNote(parent);
    } else if (type == "chatActionUpdloadingVoiceNote") {
        return new QTdChatActionUploadingVoiceNote(parent);
    }
    return Q_NULLPTR;
}
