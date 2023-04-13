#pragma once

#include <QSettings>
#include "config.h"

namespace Config
{

class Configurer
{
public:
    Configurer(Config& conf): m_conf(conf){}
    Config create(Type t);

private:
    Config m_conf;
};

} // Config


