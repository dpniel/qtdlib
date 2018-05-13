#include <QtQml>
#include <QtQml/QQmlContext>

#include "plugin.h"
#include "auth/qtdauthmanager.h"
#include "users.h"

#include "auth/qtdauthstate.h"
#include "chat/qtdchat.h"
#include "chat/qtdchatlistmodel.h"
#include "chat/qtdchatlistsortfiltermodel.h"
#include "connections/qtdconnectionstate.h"
#include "user/qtduser.h"
#include "files/qtdfile.h"
#include "files/qtdanimation.h"
#include "files/qtdphotosize.h"
#include "files/qtdaudio.h"
#include "files/qtddocument.h"
#include "files/qtdsticker.h"
#include "messages/qtdmessage.h"
#include "messages/qtdmessagelistmodel.h"
#include "messages/qtdmessagecontent.h"

#include "utils/qtdtextformatter.h"

void QTdLib::registerQmlTypes()
{
    static bool registered = false;
    if (registered) {
        return;
    }
    registered = true;

    static const char *uri = "QTelegram";
    //@uri QTelegram
    qmlRegisterType<QTdAuthManager>(uri, 1, 0, "AuthState");
    qmlRegisterType<QTdAuthParams>(uri, 1, 0, "AuthParams");
    qmlRegisterType<Users>(uri, 1, 0, "Users");
    qmlRegisterType<QTdChatListModel>(uri, 1, 0, "ChatList");
    qmlRegisterType<QTdChatListSortFilterModel>(uri, 1, 0, "SortedChatList");
    qmlRegisterType<QTdMessageListModel>(uri, 1, 0, "MessageList");

    qmlRegisterType<QTdTextFormatter>(uri, 1, 0, "TextFormatter");

    // qtdlib common
    qmlRegisterUncreatableType<QTdObject>(uri, 1, 0, "QTdObject", "Base TD c++ class");

    // qtdlib chat
    qmlRegisterUncreatableType<QTdChat>(uri, 1, 0, "QTdChat", "c++ class");
    qmlRegisterUncreatableType<QTdChatType>(uri, 1, 0, "QTdChatType", "abstract c++ class");
    qmlRegisterUncreatableType<QTdChatTypeBasicGroup>(uri, 1, 0, "QTdChatTypeBasicGroup", "c++ class");
    qmlRegisterUncreatableType<QTdChatTypePrivate>(uri, 1, 0, "QTdChatTypePrivate", "c++ class");
    qmlRegisterUncreatableType<QTdChatTypeSecret>(uri, 1, 0, "QTdChatTypeSecret", "Bc++ class");
    qmlRegisterUncreatableType<QTdChatTypeSuperGroup>(uri, 1, 0, "QTdChatTypeSuperGroup", "c++ class");
//    qmlRegisterUncreatableType<QAbstractTdObject>(uri, 1, 0, "QTdObject", "c++ class");

    // qtdlib auth
    qmlRegisterUncreatableType<QTdAuthState>(uri, 1, 0, "QTdAuthState", "Base TD auth state class");
    qmlRegisterUncreatableType<QTdAuthStateWaitParams>(uri, 1, 0, "QTdAuthStateWaitParams", "c++ class");
    qmlRegisterUncreatableType<QTdAuthStateWaitEncryptionKey>(uri, 1, 0, "QTdAuthStateWaitEncryptionKey", "c++ class");
    qmlRegisterUncreatableType<QTdAuthStateWaitPhoneNumber>(uri, 1, 0, "QTdAuthStateWaitPhoneNumber", "c++ class");
    qmlRegisterUncreatableType<QTdAuthStateWaitCode>(uri, 1, 0, "QTdAuthStateWaitCode", "c++ class");
    qmlRegisterUncreatableType<QTdAuthCodeInfo>(uri, 1, 0, "QTdAuthCodeInfo", "c++ class");
    qmlRegisterUncreatableType<QTdAuthStatePassword>(uri, 1, 0, "QTdAuthStatePassword", "c++ class");
    qmlRegisterUncreatableType<QTdAuthStateReady>(uri, 1, 0, "QTdAuthStateReady", "c++ class");
    qmlRegisterUncreatableType<QTdAuthStateLoggingOut>(uri, 1, 0, "QTdAuthStateLoggingOut", "c++ class");
    qmlRegisterUncreatableType<QTdAuthStateClosing>(uri, 1, 0, "QTdAuthStateClosing", "c++ class");
    qmlRegisterUncreatableType<QTdAuthStateClosed>(uri, 1, 0, "QTdAuthStateClosed", "c++ class");

    // qtdlib connections
    qmlRegisterUncreatableType<QTdConnectionState>(uri, 1, 0, "QTdConnectionState", "c++ class");
    qmlRegisterUncreatableType<QTdConnectionStateWaitingForNetwork>(uri, 1, 0, "QTdConnectionStateWaitingForNetwork", "c++ class");
    qmlRegisterUncreatableType<QTdConnectionStateConnectingToProxy>(uri, 1, 0, "QTdConnectionStateConnectingToProxy", "c++ class");
    qmlRegisterUncreatableType<QTdConnectionStateConnecting>(uri, 1, 0, "QTdConnectionStateConnecting", "c++ class");
    qmlRegisterUncreatableType<QTdConnectionStateUpdating>(uri, 1, 0, "QTdConnectionStateUpdating", "c++ class");
    qmlRegisterUncreatableType<QTdConnectionStateReady>(uri, 1, 0, "QTdConnectionStateReady", "c++ class");

    // qtdlib users
    qmlRegisterUncreatableType<QTdUser>(uri, 1, 0, "QTdUser", "c++ class");
    qmlRegisterUncreatableType<QTdUserStatus>(uri, 1, 0, "QTdUserStatus", "Abstract status type");
    qmlRegisterUncreatableType<QTdUserStatusEmpty>(uri, 1, 0, "QTdUserStatusEmpty", "c++ class");
    qmlRegisterUncreatableType<QTdUserStateLastMonth>(uri, 1, 0, "QTdUserStateLastMonth", "c++ class");
    qmlRegisterUncreatableType<QTdUserStatusLastWeek>(uri, 1, 0, "QTdUserStatusLastWeek", "c++ class");
    qmlRegisterUncreatableType<QTdUserStatusOffline>(uri, 1, 0, "QTdUserStatusOffline", "c++ class");
    qmlRegisterUncreatableType<QTdUserStatusOnline>(uri, 1, 0, "QTdUserStatusOnline", "c++ class");
    qmlRegisterUncreatableType<QTdUserStatusRecently>(uri, 1, 0, "QTdUserStatusRecently", "c++ class");
    qmlRegisterUncreatableType<QTdProfilePhoto>(uri, 1, 0, "QTdProfilePhoto", "c++ class");
    qmlRegisterUncreatableType<QTdLinkState>(uri, 1, 0, "QTdLinkState", "Abstract class");
    qmlRegisterUncreatableType<QTdLinkStateIsContact>(uri, 1, 0, "QTdLinkStateIsContact", "c++ class");
    qmlRegisterUncreatableType<QTdLinkStateKnowsPhoneNumber>(uri, 1, 0, "QTdLinkStateKnowsPhoneNumber", "c++ class");
    qmlRegisterUncreatableType<QTdLinkStateNone>(uri, 1, 0, "QTdLinkStateNone", "c++ class");
    qmlRegisterUncreatableType<QTdUserType>(uri, 1, 0, "QTdUserType", "Abstract class");
    qmlRegisterUncreatableType<QTdUserTypeBot>(uri, 1, 0, "QTdUserTypeBot", "c++ class");
    qmlRegisterUncreatableType<QTdUserTypeDeleted>(uri, 1, 0, "QTdUserTypeDeleted", "c++ class");
    qmlRegisterUncreatableType<QTdUserTypeRegular>(uri, 1, 0, "QTdUserTypeRegular", "c++ class");
    qmlRegisterUncreatableType<QTdUserTypeUnknown>(uri, 1, 0, "QTdUserTypeUnknown", "c++ class");

    // qtdlib files
    qmlRegisterUncreatableType<QTdFile>(uri, 1, 0, "QTdFile", "c++ class");
    qmlRegisterUncreatableType<QTdLocalFile>(uri, 1, 0, "QTdLocalFile", "c++ class");
    qmlRegisterUncreatableType<QTdRemoteFile>(uri, 1, 0, "QTdRemoteFile", "c++ class");
    qmlRegisterUncreatableType<QTdAnimation>(uri, 1, 0, "QTdAnimation", "c++ class");
    qmlRegisterUncreatableType<QTdPhoto>(uri, 1, 0, "QTdPhoto", "c++ class");
    qmlRegisterUncreatableType<QTdPhotoSize>(uri, 1, 0, "QTdPhotoSize", "c++ class");
    qmlRegisterUncreatableType<QTdAudio>(uri, 1, 0, "QTdAudio", "c++ class");
    qmlRegisterUncreatableType<QTdDocument>(uri, 1, 0, "QTdDocument", "c++ class");
    qmlRegisterUncreatableType<QTdSticker>(uri, 1, 0, "QTdSticker", "c++ class");

    // qtdlib notifications
    qmlRegisterUncreatableType<QTdNotificationSettings>(uri, 1, 0, "QTdNotificationSettings", "C++ class");

    qmlRegisterUncreatableType<QTdMessage>(uri, 1, 0, "QTdMessage", "C++ class");
    qmlRegisterUncreatableType<QTdMessageContent>(uri, 1, 0, "QTdMessageContent", "C++ class");
    qmlRegisterUncreatableType<QTdMessageText>(uri, 1, 0, "QTdMessageText", "C++ class");
    qmlRegisterUncreatableType<QTdFormattedText>(uri, 1, 0, "QTdFormattedText", "C++ class");
    qmlRegisterUncreatableType<QTdWebPage>(uri, 1, 0, "QTdWebPage", "C++ class");
}
