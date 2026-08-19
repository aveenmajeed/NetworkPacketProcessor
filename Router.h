#pragma once

#include <string>
#include <unordered_map>

class Router
{
private:
    std::unordered_map<std::string, int> routes;

public:
    Router();

    int getPort(std::string destinationIp) const;
};