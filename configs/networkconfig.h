#pragma once
#include <QHostAddress>

namespace Config
{

class NetworkConfig
{
public:
    NetworkConfig(QHostAddress&, uint);
    NetworkConfig(QHostAddress&&, uint);
    NetworkConfig(const NetworkConfig&);
    NetworkConfig(NetworkConfig&&);

    uint port() const {return m_port;}
    QHostAddress address() const {return m_address;}

private:
    QHostAddress m_address;
    uint m_port;
};

}
