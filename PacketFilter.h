#pragma once

#include <string>
#include "Packet.h"

class PacketFilter
{
private:
    std::string blockedIp;

public:
    PacketFilter();

    bool isAllowed(Packet packet) const;
};