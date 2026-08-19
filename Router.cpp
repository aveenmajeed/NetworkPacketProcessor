#include "Router.h"

Router::Router()
{ 
    routes["10.0.0"] = 1;
    routes["20.0.0"] = 2;
    routes["30.0.0"] = 3;
    routes["192.168.1"] = 4;

}

int Router::getPort(std::string destinationIp) const
{
    size_t lastDot = destinationIp.rfind('.');

    std::string network = destinationIp.substr(0, lastDot);

    return routes.at(network);
}