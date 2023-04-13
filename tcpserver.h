#pragma once

#include <QTcpServer>
#include <QObject>
#include <QList>

#include "pendingconnection.h"

class TcpServer final : public QTcpServer
{
    Q_OBJECT
public:
    static TcpServer* instance()
    {
        static TcpServer server;
        return &server;
    }

    const QString toString() const;
    void listen();
    void setAddress(const QHostAddress&);
    void setPort(uint32_t);
    const QHostAddress address() const { return m_address; }
    const int port() const { return m_port; }

protected:
    void incomingConnection(qintptr handle) override;

private:
    TcpServer() = default;
    TcpServer(const TcpServer&) = delete;
    TcpServer(TcpServer&&) = delete;
    TcpServer operator=(const TcpServer&) = delete;
    TcpServer operator=(TcpServer&&) = delete;
    ~TcpServer();

    QHostAddress m_address = QHostAddress::Any;
    uint32_t m_port = 0;
    QList<PendingConnection*> m_pendingConnections;
};

