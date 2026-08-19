#include "PacketQueue.h"

void PacketQueue::addPacket(Packet packet)
{
    packets.push(packet);
}

Packet PacketQueue::getNextPacket()
{
    return packets.front();
}

void PacketQueue::removePacket()
{
    packets.pop();
}

bool PacketQueue::isEmpty() const
{
    return packets.empty();
}