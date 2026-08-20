cmake_minimum_required(VERSION 3.16)

project(NetworkPacketProcessor)

set(CMAKE_CXX_STANDARD 17)

add_executable(network_processor
    main.cpp
    Packet.cpp
    PacketGenerator.cpp
    PacketQueue.cpp
    PacketFilter.cpp
    Router.cpp
)

add_executable(tests
    tests.cpp
    Packet.cpp
    PacketQueue.cpp
    PacketFilter.cpp
    Router.cpp
)