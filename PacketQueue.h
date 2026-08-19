#pragma once

#include <queue>
#include "Packet.h"
#include <mutex>

class PacketQueue
{
private:
    std::queue<Packet> highPriority;
    std::queue<Packet> normalPriority;
    std::queue<Packet> lowPriority;
    
    mutable std::mutex queueMutex;


public:
    void addPacket(Packet packet);
    bool getNextPacket(Packet& packet);
    bool isEmpty() const;
};