#include "networkconfig.h"

namespace Config
{

NetworkConfig::NetworkConfig(QHostAddress& addr, uint port)
    : m_address(addr), m_port(port) {}

NetworkConfig::NetworkConfig(QHostAddress&& addr, uint port)
{
    m_address = std::move(addr);
    m_port = port;
}

NetworkConfig::NetworkConfig(const NetworkConfig& other)
{
    m_address = other.m_address;
    m_port = other.m_port;
}

NetworkConfig::NetworkConfig(NetworkConfig&& other)
{
    m_address = std::move(other.m_address);
    m_port = other.m_port;
}

} // Config
