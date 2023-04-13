#pragma once
#include <QHostAddress>

#include "config.h"

namespace Config
{

class NetworkConfig : public Config
{
public:
    NetworkConfig(QHostAddress&, uint);
    NetworkConfig(QHostAddress&&, uint);
    NetworkConfig(const NetworkConfig&);
    NetworkConfig(NetworkConfig&&);

private:
    QHostAddress m_address;
    uint m_port;
};

}
