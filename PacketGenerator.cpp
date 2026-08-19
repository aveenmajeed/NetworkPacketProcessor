#include "PacketGenerator.h"
#include <random>

Packet PacketGenerator::generatePacket(int packetId)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 2);
    std::uniform_int_distribution<int> priorityDist(1, 3);
    std::uniform_int_distribution<int> sizeDist(64, 1500);
    std::uniform_int_distribution<int> ipDist(1, 254);

    int choice = dist(gen);
    int priority = priorityDist(gen);
    int size = sizeDist(gen);  
    
    int sourceNum = ipDist(gen);
    int destinationNum = ipDist(gen);
    std::string sourceIp = "192.168.1." + std::to_string(sourceNum);
    std::string destinationIp = "10.0.0." + std::to_string(destinationNum);

    std::string protocol;

    if (choice == 0)
    {
        protocol = "TCP";
    }
    else if (choice == 1)
    {
        protocol = "UDP";
    }
    else
    {
        protocol = "ICMP";
    }

   

  

    return Packet(packetId, sourceIp, destinationIp, protocol, priority, size);
}