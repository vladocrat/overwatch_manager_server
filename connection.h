#pragma once

#include <QTcpSocket>
#include <QObject>
#include <QByteArray>
#include <QMap>

class Connection : public QObject
{
    Q_OBJECT
public:
    Connection();
    virtual ~Connection();

    virtual bool send(uint32_t command, const QByteArray& data = "");
    virtual void readUserData(QByteArray&);
    virtual int readCommand(QDataStream&);

    QTcpSocket* clearSocket();

    QTcpSocket* socket() const;
    void setScoket(QTcpSocket* con);

private:
    bool checkConnection() const;

    QTcpSocket*  m_socket;
    uint32_t m_packageSize = -1;
};

