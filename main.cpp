#include <QCoreApplication>
#include "configurer.h"
#include "networkconfig.h"
#include "tcpserver.h"

#define server TcpServer::instance()

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString path = "settings.ini";
    auto config = Config::Configurer(path);
    auto networkConfig = config.configureNetwork();
    server->setAddress(networkConfig.address());
    server->setPort(networkConfig.port());
    server->listen();

    return a.exec();
}
