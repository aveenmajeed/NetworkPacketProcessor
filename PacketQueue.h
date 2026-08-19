#pragma once

#include <queue>
#include "Packet.h"

class PacketQueue
{
private:
    std::queue<Packet> packets;

public:
    void addPacket(Packet packet);
    Packet getNextPacket();
    void removePacket();
    bool isEmpty() const;
};