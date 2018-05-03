#include "qtdauthparametersresponse.h"

QTdAuthParametersResponse::QTdAuthParametersResponse(QObject *parent) : QTdRequest(parent)
{
}

void QTdAuthParametersResponse::setParameters(QTdAuthParams *params)
{
    m_params = params->marshalJson();
}

QJsonObject QTdAuthParametersResponse::marshalJson()
{
    return QJsonObject{
        {"@type", "setTdlibParameters"},
        {"parameters", m_params},
    };
}
