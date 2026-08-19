#include "Packet.h"

Packet::Packet()
{
    packetId = 0;
    sourceIp = "";
    destinationIp = "";
    protocol = "";
    priority = 0;
    size = 0;
}



Packet::Packet(int packetId, std::string sourceIp, std::string destinationIp,
               std::string protocol, int priority, int size){
    this->packetId = packetId;
this->sourceIp = sourceIp;
this->destinationIp = destinationIp;
this->protocol = protocol;
this->priority = priority;
this->size = size;

}


int Packet::getPacketId() const{
    return packetId;
}

std::string Packet::getSourceIp() const
{
    return sourceIp;
}

std::string Packet::getDestinationIp() const
{
    return destinationIp;
}

std::string Packet::getProtocol() const
{
    return protocol;
}

int Packet::getPriority() const
{
    return priority;
}

int Packet::getSize() const
{
    return size;
}