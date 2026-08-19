#include "Packet.h"
#include <iostream>

int main()
{
    Packet packet1(1, "192.168.1.10", "10.0.0.25", "TCP", 2, 1500);
    std::cout << "Packet ID: " << packet1.getPacketId() << std::endl;
    std::cout << "Source IP: " << packet1.getSourceIp() << std::endl;
    std::cout << "Destination IP: " << packet1.getDestinationIp() << std::endl;
    std::cout << "Protocol: " << packet1.getProtocol() << std::endl;
    std::cout << "Priority: " << packet1.getPriority() << std::endl;
    std::cout << "Size: " << packet1.getSize() << " bytes" << std::endl;


    return 0;
}