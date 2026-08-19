#include "Packet.h"
#include <iostream>
#include "PacketGenerator.h"
#include <vector>

int main()
{
    PacketGenerator generator;
    std::vector<Packet> packets;

     // Generate 10 random packets and store them in the vector
    for (int i = 1; i <= 10; i++)
    {
        Packet packet = generator.generatePacket(i);
        packets.push_back(packet);
    }

    // Print every packet in the vector
    for (Packet packet : packets)
    {

        Packet packet1 = generator.generatePacket(1);
        std::cout << "Packet ID: " << packet1.getPacketId() << std::endl;
        std::cout << "Source IP: " << packet1.getSourceIp() << std::endl;
        std::cout << "Destination IP: " << packet1.getDestinationIp() << std::endl;
        std::cout << "Protocol: " << packet1.getProtocol() << std::endl;
        std::cout << "Priority: " << packet1.getPriority() << std::endl;
        std::cout << "Size: " << packet1.getSize() << " bytes" << std::endl;

    }


    return 0;
}