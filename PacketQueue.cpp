#include "PacketQueue.h"

void PacketQueue::addPacket(Packet packet)
{
    std::lock_guard<std::mutex> lock(queueMutex);

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

bool PacketQueue::getNextPacket(Packet& packet)
{
    std::lock_guard<std::mutex> lock(queueMutex);

    if (!highPriority.empty())
    {
        packet = highPriority.front();
        highPriority.pop();
        return true;
    }
    else if (!normalPriority.empty())
    {
        packet = normalPriority.front();
        normalPriority.pop();
        return true;
    }
    else if (!lowPriority.empty())
    {
        packet = lowPriority.front();
        lowPriority.pop();
        return true;
    }

    return false;
}



bool PacketQueue::isEmpty() const
{
    std::lock_guard<std::mutex> lock(queueMutex);

    return highPriority.empty() &&
           normalPriority.empty() &&
           lowPriority.empty();
}