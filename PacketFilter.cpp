#include "PacketFilter.h"

PacketFilter::PacketFilter()
{
    blockedIp = "192.168.1.50";
}

bool PacketFilter::isAllowed(Packet packet) const
{
    if (packet.getSourceIp() == blockedIp)
    {
        return false;
    }

    return true;
}