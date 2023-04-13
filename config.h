#pragma once

namespace Config
{

class Configurer;

enum Type
{
    Network,
    Database
};


class Config
{
public:
    static Configurer build();

private:
    friend Configurer;
};


} // Config


