#include "configurer.h"
#include "networkconfig.h"
#include "dbconfig.h"

namespace Config
{

Config Configurer::create(Type t)
{
    QSettings settings("", QSettings::IniFormat);

    switch(t)
    {
    case Network:
    {
        settings.beginGroup("Network");
        auto address = settings.value("address", QHostAddress::LocalHost).toString();
        auto port = settings.value("port", 8080).toUInt();
        return NetworkConfig(QHostAddress(address), port);
    }
    case Database:
        return DBConfig();
    default:
        break;
    }
}

} // Config
