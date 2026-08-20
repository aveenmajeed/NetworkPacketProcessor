#include <iostream>
#include <thread>
#include <functional>

#include "Packet.h"
#include "PacketGenerator.h"
#include "PacketQueue.h"
#include "Router.h"
#include "PacketFilter.h"
#include <mutex>
#include <chrono>
#include <vector>
#include <cmath>

std::mutex coutMutex;


// Worker thread processes packets from the queue
void worker(int workerId, PacketQueue& packets, Router& router)
{
    Packet packet;

    while (packets.getNextPacket(packet))
    {
        int port = router.getPort(packet.getDestinationIp());
        double result = 0;

        for (int i = 0; i < 1000; i++)
        {
            result += std::sqrt(packet.getSize() + i);
        }

       // {
           // std::lock_guard<std::mutex> lock(coutMutex);

          //  std::cout << "Worker " << workerId << " processed Packet " << packet.getPacketId() << " -> Port " << port << std::endl;
        //}
    }
}

int main()
{
    PacketGenerator generator;
    PacketQueue packets;
    Router router;
    PacketFilter filter;
    int blockedCount = 0;
    int totalPackets = 10000;
    int workerCount = 4;

    // Generate 10 random packets
    for (int i = 1; i <= totalPackets; i++)
    {
        Packet packet = generator.generatePacket(i);

        // Only add allowed packets to the queue
        if (filter.isAllowed(packet))
        {
            packets.addPacket(packet);
        }
        else
        {
             blockedCount++;
        }
    }

    auto start = std::chrono::high_resolution_clock::now();

    // Create a worker thread to process the packets
   std::vector<std::thread> workers;

    for (int i = 1; i <= workerCount; i++)
    {
        workers.emplace_back(worker, i, std::ref(packets), std::ref(router));
    }

    for (std::thread& t : workers)
    {
        t.join();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    int processedCount = totalPackets - blockedCount;
    double seconds = duration.count() / 1000000.0;

    double throughput = processedCount / seconds;
    double averageTime = static_cast<double>(duration.count()) / processedCount;

    std::cout << "\nNETWORK PROCESSOR RESULTS" << std::endl;
    std::cout << "-------------------------" << std::endl;

    std::cout << "Packets Generated: " << totalPackets << std::endl;
    std::cout << "Packets Processed: " << processedCount << std::endl;
    std::cout << "Packets Blocked:   " << blockedCount << std::endl;
    std::cout << "Workers:           " << workerCount << std::endl;
    std::cout << "Processing Time:   " << duration.count() << " microseconds" << std::endl;
    std::cout << "Throughput:        " << throughput << " packets/second" << std::endl;
    std::cout << "Average Time:      " << averageTime << " microseconds/packet" << std::endl;
    return 0;
}