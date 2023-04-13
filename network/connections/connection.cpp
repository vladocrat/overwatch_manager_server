#include "connection.h"

#include <QDataStream>
#include <assert.h>

Connection::Connection()
{
    m_socket = new QTcpSocket;
}

Connection::~Connection()
{
    assert(m_socket);

    if (m_socket)
    {
        m_socket->close();
        m_socket->deleteLater();
    }
}

bool Connection::send(uint32_t command, const QByteArray& data)
{
    if (!checkConnection())
    {
        return false;
    }

    QByteArray msg;
    QDataStream stream(&msg, QIODevice::WriteOnly);
    QDataStream socketStream(m_socket);
    stream << command << data;
    qDebug() << msg;
    socketStream << msg.size() << msg;

    if (!m_socket->flush())
    {
        qDebug() << "failed to flush socket";

        return false;
    }

    return true;
}

void Connection::readUserData(QByteArray& data)
{
    if (m_socket->bytesAvailable() >= sizeof(uint32_t) && m_packageSize == -1)
    {
        QDataStream buffer(m_socket);
        buffer >> m_packageSize;
    }

    if (m_socket->bytesAvailable() < m_packageSize)
    {
        return;
    }

    QDataStream buffer(m_socket);
    buffer >> data;
    m_packageSize = -1;
}

int Connection::readCommand(QDataStream& stream)
{
    uint32_t command;
    stream >> command;

    return command;
}

QTcpSocket* Connection::clearSocket()
{
    if (!m_socket->disconnect())
    {
        qDebug() << "failed to disconnect socket handlers";

        m_socket->close();
        return nullptr;
    }

    auto copy = m_socket;
    m_socket = nullptr;

    return copy;
}

QTcpSocket* Connection::socket() const
{
    return m_socket;
}

void Connection::setScoket(QTcpSocket* socket)
{
    m_socket = socket;
}

bool Connection::checkConnection() const
{
    if (m_socket->state() != QTcpSocket::ConnectedState)
    {
        qDebug() << "socket not connected";

        return false;
    }

    return true;
}
