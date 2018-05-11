set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package(Qt5Core)
find_package(Qt5Qml)
find_package(Qt5Quick)
find_package(Qt5Concurrent)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(QTDLIB "QTdlib")

set(
    SRC
    auth/qtdauthstate.cpp
    auth/qtdauthcode.cpp
    auth/qtdauthstatefactory.cpp
    auth/qtdauthmanager.cpp
    auth/qtdauthparams.cpp
    auth/requests/qtdauthparametersresponse.cpp
    auth/requests/qtdauthencryptionkeyresponse.cpp
    auth/requests/qtdauthphonenumberresponse.cpp
    auth/requests/qtdauthcoderesponse.cpp
    chat/qtdchat.cpp
    chat/qtdchataction.cpp
    chat/qtdchatactionfactory.cpp
    chat/qtdchatmemberstatus.cpp
    chat/qtdbasicgroupchat.cpp
    chat/qtdsecretchat.cpp
    chat/qtdsecretchatstate.cpp
    chat/qtdsupergroupchat.cpp
    chat/qtdchattype.cpp
    chat/qtdchattypefactory.cpp
    chat/qtdchatlistmodel.cpp
    chat/qtdchatmember.cpp
    chat/qtdchatlistsortfiltermodel.cpp
    chat/requests/qtdgetbasicgrouprequest.cpp
    chat/requests/qtdgetchatsrequest.cpp
    chat/requests/qtdreportchatrequest.cpp
    chat/requests/qtdgetsecretchatrequest.cpp
    chat/requests/qtdgetsupergrouprequest.cpp
    chat/requests/qtdgetsupergroupfullinforequest.cpp
    chat/requests/qtdopenchatrequest.cpp
    chat/requests/qtdclosechatrequest.cpp
    chat/requests/qtdsetpinnedchatsrequest.cpp
    chat/requests/qtdsetchattitlerequest.cpp
    common/qabstracttdobject.cpp
    common/qabstractint53id.cpp
    common/qabstractint32id.cpp
    common/qabstractint64id.cpp
    common/qtdint.cpp
    common/qtdrequest.cpp
    client/qtdhandle.cpp
    client/qtdclient.cpp
    client/qtdthread.cpp
    connections/qtdconnectionstate.cpp
    connections/qtdconnectionstatefactory.cpp
    files/qtdfile.cpp
    files/qtdaudio.cpp
    files/qtdlocalfile.cpp
    files/qtdremotefile.cpp
    files/qtddownloadfilerequest.cpp
    files/qtddocument.cpp
    files/qtdphoto.cpp
    files/qtdphotosize.cpp
    files/qtdanimation.cpp
    files/qtdsticker.cpp
    messages/qtdtextentity.cpp
    messages/qtdtextentitytype.cpp
    messages/qtdmessage.cpp
    messages/qtdmessagecontent.cpp
    messages/qtdformattedtext.cpp
    messages/qtdwebpage.cpp
    messages/qtdmessagecontentfactory.cpp
    messages/qtdmessagesendingstate.cpp
    messages/qtdmessagelistmodel.cpp
    models/QmlObjectListModel.cpp
    models/QmlVariantListModel.cpp
    notifications/qtdnotificationsettings.cpp
    user/qtduser.cpp
    user/qtdusers.cpp
    user/qtdlinkstate.cpp
    user/qtdlinkstatefactory.cpp
    user/qtduserstatus.cpp
    user/qtdusertype.cpp
    user/qtduserstatusfactory.cpp
    user/qtdprofilephoto.cpp
    user/requests/qtdblockuserrequest.cpp
    quick/plugin.cpp
    quick/users.cpp
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

add_library(${QTDLIB} SHARED ${SRC})
target_link_libraries(${QTDLIB} Qt5::Core Qt5::Quick Qt5::Qml Qt5::Concurrent Td::TdJson)
target_include_directories(${QTDLIB} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
get_filename_component(QTDLIB_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
#set_property(TARGET ${QTDLIB} PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${QTDLIB_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

execute_process(
    COMMAND dpkg-architecture -qDEB_HOST_MULTIARCH
    OUTPUT_VARIABLE ARCH_TRIPLET
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(QT_IMPORTS_DIR "/lib/${ARCH_TRIPLET}")

install(TARGETS ${PLUGIN} DESTINATION ${QT_IMPORTS_DIR})
