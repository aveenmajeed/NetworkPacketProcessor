#pragma once

#include <queue>
#include "Packet.h"

class PacketQueue
{
private:
    std::queue<Packet> highPriority;
    std::queue<Packet> normalPriority;
    std::queue<Packet> lowPriority;


public:
    void addPacket(Packet packet);
    Packet getNextPacket();
    void removePacket();
    bool isEmpty() const;
};