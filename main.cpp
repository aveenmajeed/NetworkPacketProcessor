#include "Packet.h"
#include <iostream>
#include "PacketGenerator.h"
#include "PacketQueue.h"

int main()
{
    PacketGenerator generator;
    PacketQueue packets;

     // Generate 10 random packets and store them in the vector
    for (int i = 1; i <= 10; i++)
    {
        Packet packet = generator.generatePacket(i);
        packets.addPacket(packet);
    }

    // Print every packet in the vector
    while (!packets.isEmpty())
    {

        Packet packet = packets.getNextPacket();
        std::cout << "Packet ID: " << packet.getPacketId() << std::endl;
        std::cout << "Source IP: " << packet.getSourceIp() << std::endl;
        std::cout << "Destination IP: " << packet.getDestinationIp() << std::endl;
        std::cout << "Protocol: " << packet.getProtocol() << std::endl;
        std::cout << "Priority: " << packet.getPriority() << std::endl;
        std::cout << "Size: " << packet.getSize() << " bytes" << std::endl;
        std::cout << std::endl;

        packets.removePacket();

    }


    return 0;
}