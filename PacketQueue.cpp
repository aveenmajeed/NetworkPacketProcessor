#include "PacketQueue.h"

void PacketQueue::addPacket(Packet packet)
{
    if (packet.getPriority() == 3)
    {
        highPriority.push(packet);
    }
    else if (packet.getPriority() == 2)
    {
        normalPriority.push(packet);
    }
    else
    {
        lowPriority.push(packet);
    }
}

Packet PacketQueue::getNextPacket()
{
    if (!highPriority.empty())
    {
        return highPriority.front();
    }
    else if (!normalPriority.empty())
    {
        return normalPriority.front();
    }
    else
    {
        return lowPriority.front();
    }
}

void PacketQueue::removePacket()
{
    if (!highPriority.empty())
    {
        highPriority.pop();
    }
    else if (!normalPriority.empty())
    {
        normalPriority.pop();
    }
    else
    {
        lowPriority.pop();
    }
}

bool PacketQueue::isEmpty() const
{
    return highPriority.empty() && normalPriority.empty() && lowPriority.empty();
}