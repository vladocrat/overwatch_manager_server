#pragma once

#include <QSettings>
#include "networkconfig.h"

namespace Config
{

class Configurer
{
public:
    Configurer(const QString&);

    NetworkConfig configureNetwork();

private:
    QString m_filePath;
};

} // Config


