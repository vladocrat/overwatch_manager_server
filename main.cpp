#include <QCoreApplication>
#include "configurer.h"
#include "networkconfig.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = "settings.ini";

    auto config = Config::Configurer(path);
    auto networkConfig = config.configureNetwork();
    qDebug() << networkConfig.address() << " " << networkConfig.port();

    return a.exec();
}
