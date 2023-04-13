#pragma once

#include <QByteArray>
#include <QObject>

#include "connection.h"

/*!
 * Any unauthorized socket is considered a pending connection
 *
 * After socket is authorized it is moved to \class UserConnection
 */
class PendingConnection : public Connection
{
    Q_OBJECT;
public:
    PendingConnection();

private:
    void handleData();
};
