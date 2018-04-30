#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include <QObject>
#include "qtdauthstate.h"
#include "qtdauthparams.h"

class QTdAuthManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(State state READ state NOTIFY stateChanged)
    Q_PROPERTY(QTdAuthState* type READ type NOTIFY stateChanged)
    Q_PROPERTY(QTdAuthParams* params READ params WRITE setParams NOTIFY paramsChanged)
public:
    explicit QTdAuthManager(QObject *parent = nullptr);

    enum State {
        Invalid,
        WaitTdParams,
        WaitEncryptionKey,
        WaitPhoneNumber,
        WaitCode,
        WaitPassword,
        Ready,
        LoggingOut,
        Closing,
        Closed
    };
    Q_ENUM(State)
    State state() const;
    QTdAuthState *type() const;

    QTdAuthParams* params() const;

public slots:
    void setParams(QTdAuthParams* params);
    void sendParams();
    void setEncryptionKey(const QString &key);
    void sendPhoneNumber(const QString &number);
    void sendCode(const QString &code);

signals:
    void stateChanged(State state);
    void waitingForTdParams();
    void waitingForEncryptionKey();
    void waitingForPhoneNumber();
    void waitingForCode();
    void waitingForPassword();
    void ready();
    void loggingOut();
    void closing();
    void closed();

    void paramsChanged(QTdAuthParams* params);

private slots:
    void handleAuthStateChanged(QTdAuthState *state);

private:
    State m_state;
    QTdAuthParams* m_params;
};

#endif // AUTHMANAGER_H
