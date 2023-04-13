#include "tcpserver.h"

#include <QDebug>

TcpServer::~TcpServer()
{
    for (auto pc : qAsConst(m_pendingConnections))
    {
        pc->deleteLater();
    }
}

const QString TcpServer::toString() const
{
    return QString()
            .append("address=")
            .append(m_address.toString())
            .append(" port=")
            .append(QString::number(m_port));
}

void TcpServer::listen()
{
    if (!QTcpServer::listen(m_address, m_port))
    {
        qDebug() << "failed to listen on: " << toString();
    }

    qDebug() << "listening on: " << toString();
}

void TcpServer::setAddress(const QHostAddress& address)
{
    m_address = address;
}

void TcpServer::setPort(uint32_t port)
{
    m_port = port;
}

void TcpServer::incomingConnection(qintptr handle)
{
    auto pendingConnection = new PendingConnection;
    pendingConnection->socket()->setSocketDescriptor(handle);

    connect(pendingConnection->socket(), &QTcpSocket::disconnected, [this, pendingConnection]()
    {
        m_pendingConnections.removeOne(pendingConnection);
    });

    qDebug() << "new connection";
    m_pendingConnections.append(pendingConnection);
}
