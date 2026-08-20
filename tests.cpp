#include <iostream>
#include "Router.h"
#include "Packet.h"
#include "PacketFilter.h"
#include "PacketQueue.h"

int main()
{
    std::cout << "Testing Router..." << std::endl;

    Router router;

    if (router.getPort("10.0.0.25") == 1)
    {
        std::cout << "Test 1 passed" << std::endl;
    }
    else
    {
        std::cout << "Test 1 failed" << std::endl;
    }

    if (router.getPort("20.0.0.50") == 2)
    {
        std::cout << "Test 2 passed" << std::endl;
    }
    else
    {
        std::cout << "Test 2 failed" << std::endl;
    }

    if (router.getPort("30.0.0.75") == 3)
    {
        std::cout << "Test 3 passed" << std::endl;
    }
    else
    {
        std::cout << "Test 3 failed" << std::endl;
    }

    if (router.getPort("192.168.1.20") == 4)
    {
        std::cout << "Test 4 passed" << std::endl;
    }
    else
    {
        std::cout << "Test 4 failed" << std::endl;
    }


    std::cout << "\nTesting Packet Filter..." << std::endl;

    PacketFilter filter;

    Packet blockedPacket(1, "192.168.1.50", "10.0.0.25", "TCP", 2, 1000);
    Packet allowedPacket(2, "192.168.1.25", "10.0.0.25", "TCP", 2, 1000);

    if (!filter.isAllowed(blockedPacket))
    {
        std::cout << "Test 5 passed" << std::endl;
    }
    else
    {
        std::cout << "Test 5 failed" << std::endl;
    }

    if (filter.isAllowed(allowedPacket))
    {
        std::cout << "Test 6 passed" << std::endl;
    }
    else
    {
        std::cout << "Test 6 failed" << std::endl;
    }


    std::cout << "\nTesting Priority Queue..." << std::endl;

    PacketQueue queue;

    Packet low(1, "192.168.1.1", "10.0.0.1", "TCP", 1, 500);
    Packet high(2, "192.168.1.2", "10.0.0.2", "TCP", 3, 500);
    Packet normal(3, "192.168.1.3", "10.0.0.3", "TCP", 2, 500);

    queue.addPacket(low);
    queue.addPacket(high);
    queue.addPacket(normal);

    Packet packet;

    queue.getNextPacket(packet);

    if (packet.getPacketId() == 2)
    {
        std::cout << "Test 7 passed" << std::endl;
    }
    else
    {
        std::cout << "Test 7 failed" << std::endl;
    }

    queue.getNextPacket(packet);

    if (packet.getPacketId() == 3)
    {
        std::cout << "Test 8 passed" << std::endl;
    }
    else
    {
        std::cout << "Test 8 failed" << std::endl;
    }

    queue.getNextPacket(packet);

    if (packet.getPacketId() == 1)
    {
        std::cout << "Test 9 passed" << std::endl;
    }
    else
    {
        std::cout << "Test 9 failed" << std::endl;
    }

    return 0;
}