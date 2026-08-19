#pragma once
#include <string>

class Packet{

    private:
    int packetId;
    std::string sourceIp;
    std::string destinationIp;
    std::string protocol;
    int priority;
    int size;


    public:

    Packet();

    Packet(int packetId, std::string sourceIp,std::string destinationIp,
    std::string protocol, int priority, int size);

    int getPacketId() const; // const meansit wont modify Packet object
    std::string getSourceIp() const;
    std::string getDestinationIp() const;
    std::string getProtocol() const;
    int getPriority() const;
    int getSize() const;


};