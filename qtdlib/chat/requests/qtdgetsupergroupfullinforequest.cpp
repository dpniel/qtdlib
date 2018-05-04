#include "qtdgetsupergroupfullinforequest.h"

QTdGetSuperGroupFullInfoRequest::QTdGetSuperGroupFullInfoRequest(QObject *parent) : QTdRequest(parent)
{

}

void QTdGetSuperGroupFullInfoRequest::setSupergroupId(const qint32 &id)
{
    m_id = id;
}

QJsonObject QTdGetSuperGroupFullInfoRequest::marshalJson()
{
    return QJsonObject{
        {"@type", "getSupergroupFullInfo"},
        {"supergroup_id", m_id},
        {"@extra", QString::number(m_id)},
    };
}
