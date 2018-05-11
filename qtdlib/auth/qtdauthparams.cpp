#include "qtdauthparams.h"
#include <QCoreApplication>
#include <QStandardPaths>

QTdAuthParams::QTdAuthParams(QObject *parent) : QTdObject(parent),
    m_useTestDC(false),
    m_useFileDatabase(true),
    m_useChatInfoDatabase(true),
    m_useMessageDatabase(true),
    m_useSecretChats(true),
    m_useStorageOptimizer(true),
    m_apiID(0)
{
    m_systemLanguageCode = QStringLiteral("en");
    m_deviceModel = QStringLiteral("Ubuntu Phone");
    m_systemVersion = QStringLiteral("xenial");
    m_applicationVersion = QCoreApplication::applicationVersion();
    m_databaseDirectory = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).append("/database");
    m_filesDirectory = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).append("/files");
}

bool QTdAuthParams::useTestDC() const
{
    return m_useTestDC;
}

bool QTdAuthParams::useFileDatabase() const
{
    return m_useFileDatabase;
}

bool QTdAuthParams::useChatInfoDatabase() const
{
    return m_useChatInfoDatabase;
}

bool QTdAuthParams::useMessageDatabase() const
{
    return m_useMessageDatabase;
}

bool QTdAuthParams::useSecretChats() const
{
    return m_useSecretChats;
}

bool QTdAuthParams::useStorageOptimizer() const
{
    return m_useStorageOptimizer;
}

qint32 QTdAuthParams::apiID() const
{
    return m_apiID;
}

QString QTdAuthParams::apiHash() const
{
    return m_apiHash;
}

QString QTdAuthParams::systemLanguageCode() const
{
    return m_systemLanguageCode;
}

QString QTdAuthParams::deviceModel() const
{
    return m_deviceModel;
}

QString QTdAuthParams::systemVersion() const
{
    return m_systemVersion;
}

QString QTdAuthParams::applicationVersion() const
{
    return m_applicationVersion;
}

QString QTdAuthParams::databaseDirectory() const
{
    return m_databaseDirectory;
}

QString QTdAuthParams::filesDirectory() const
{
    return m_filesDirectory;
}

QJsonObject QTdAuthParams::marshalJson()
{
    return QJsonObject{
        {"use_test_dc", m_useTestDC },
        {"use_file_database", m_useFileDatabase},
        { "use_chat_info_database", m_useChatInfoDatabase },
        { "use_message_database", m_useMessageDatabase },
        { "use_secret_chats", m_useSecretChats },
        { "api_id", m_apiID },
        { "api_hash", m_apiHash },
        { "system_language_code", "en" },
        { "device_model", m_deviceModel },
        { "system_version", m_systemVersion },
        { "application_version", m_applicationVersion },
        { "enable_storage_optimizer", m_useStorageOptimizer },
        { "database_directory", m_databaseDirectory },
        { "files_directory", m_filesDirectory },
    };
}

void QTdAuthParams::setUseTestDC(bool useTestDC)
{
    if (m_useTestDC == useTestDC)
        return;

    m_useTestDC = useTestDC;
    emit useTstDCChanged(m_useTestDC);
}

void QTdAuthParams::setUseFileDatabase(bool useFileDatabase)
{
    if (m_useFileDatabase == useFileDatabase)
        return;

    m_useFileDatabase = useFileDatabase;
    emit useFileDatabaseChanged(m_useFileDatabase);
}

void QTdAuthParams::setUseChatInfoDatabase(bool useChatInfoDatabase)
{
    if (m_useChatInfoDatabase == useChatInfoDatabase)
        return;

    m_useChatInfoDatabase = useChatInfoDatabase;
    emit useChatInfoDatabaseChanged(m_useChatInfoDatabase);
}

void QTdAuthParams::setUseMessageDatabase(bool useMessageDatabase)
{
    if (m_useMessageDatabase == useMessageDatabase)
        return;

    m_useMessageDatabase = useMessageDatabase;
    emit useMessageDatabaseChanged(m_useMessageDatabase);
}

void QTdAuthParams::setUseSecretChats(bool useSecretChats)
{
    if (m_useSecretChats == useSecretChats)
        return;

    m_useSecretChats = useSecretChats;
    emit useSecretChatsChanged(m_useSecretChats);
}

void QTdAuthParams::setUseStorageOptimizer(bool useStorageOptimizer)
{
    if (m_useStorageOptimizer == useStorageOptimizer)
        return;

    m_useStorageOptimizer = useStorageOptimizer;
    emit useStorageOptimizerChanged(m_useStorageOptimizer);
}

void QTdAuthParams::setApiID(qint32 apiID)
{
    if (m_apiID == apiID)
        return;

    m_apiID = apiID;
    emit apiIDChanged(m_apiID);
}

void QTdAuthParams::setApiHash(QString apiHash)
{
    if (m_apiHash == apiHash)
        return;

    m_apiHash = apiHash;
    emit apiHashChanged(m_apiHash);
}

void QTdAuthParams::setSystemLanguageCode(QString systemLanguageCode)
{
    if (m_systemLanguageCode == systemLanguageCode)
        return;

    m_systemLanguageCode = systemLanguageCode;
    emit systemLanguageCodeChanged(m_systemLanguageCode);
}

void QTdAuthParams::setDeviceModel(QString deviceModel)
{
    if (m_deviceModel == deviceModel)
        return;

    m_deviceModel = deviceModel;
    emit deviceModelChanged(m_deviceModel);
}

void QTdAuthParams::setSystemVersion(QString systemVersion)
{
    if (m_systemVersion == systemVersion)
        return;

    m_systemVersion = systemVersion;
    emit systemVersionChanged(m_systemVersion);
}

void QTdAuthParams::setApplicationVersion(QString applicationVersion)
{
    if (m_applicationVersion == applicationVersion)
        return;

    m_applicationVersion = applicationVersion;
    emit applicationVersionChanged(m_applicationVersion);
}

void QTdAuthParams::setDatabaseDirectory(QString databaseDirectory)
{
    if (m_databaseDirectory == databaseDirectory)
        return;

    m_databaseDirectory = databaseDirectory;
    emit databaseDirectoryChanged(m_databaseDirectory);
}

void QTdAuthParams::setFilesDirectory(QString filesDirectory)
{
    if (m_filesDirectory == filesDirectory)
        return;

    m_filesDirectory = filesDirectory;
    emit filesDirectoryChanged(m_filesDirectory);
}
