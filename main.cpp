#include <iostream>
#include <thread>
#include <functional>

#include "Packet.h"
#include "PacketGenerator.h"
#include "PacketQueue.h"
#include "Router.h"
#include "PacketFilter.h"
#include <mutex>

std::mutex coutMutex;


// Worker thread processes packets from the queue
void worker(int workerId, PacketQueue& packets, Router& router)
{
    Packet packet;

    while (packets.getNextPacket(packet))
    {
        int port = router.getPort(packet.getDestinationIp());

        {
            std::lock_guard<std::mutex> lock(coutMutex);

            std::cout << "Worker " << workerId
                      << " processed Packet "
                      << packet.getPacketId()
                      << " -> Port "
                      << port
                      << std::endl;
        }
    }
}

int main()
{
    PacketGenerator generator;
    PacketQueue packets;
    Router router;
    PacketFilter filter;

    // Generate 10 random packets
    for (int i = 1; i <= 10; i++)
    {
        Packet packet = generator.generatePacket(i);

        // Only add allowed packets to the queue
        if (filter.isAllowed(packet))
        {
            packets.addPacket(packet);
        }
        else
        {
            std::cout << "Packet "
                      << packet.getPacketId()
                      << " was blocked"
                      << std::endl;
        }
    }

    // Create a worker thread to process the packets
    std::thread worker1(worker, 1, std::ref(packets), std::ref(router));
    std::thread worker2(worker, 2, std::ref(packets), std::ref(router));
    std::thread worker3(worker, 3, std::ref(packets), std::ref(router));

    worker1.join();
    worker2.join();
    worker3.join();
    return 0;
}