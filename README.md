# Network Packet Processor

This is a C++ project that simulates a basic network packet processing system.

The program creates network packets with different IP addresses, protocols, priorities, and sizes. It then filters the packets, puts them in a priority queue, routes them to different ports, and uses multiple worker threads to process them.

## What It Does

- Generates random network packets
- Gives each packet a source IP, destination IP, protocol, priority, and size
- Blocks certain packets using a packet filter
- Processes higher priority packets first
- Routes packets to different output ports based on their destination IP
- Uses multiple threads to process packets at the same time
- Uses mutexes so multiple threads can safely use the same packet queue
- Measures processing time, throughput, and average time per packet

## Multithreading

The program uses multiple worker threads that all take packets from the same queue.

Since multiple workers can try to access the queue at the same time, I used a mutex to make sure only one worker can change the queue at a time.

I tested the program with different numbers of workers to see how much multithreading improved the processing speed.

## Performance Results

I tested the program using 10,000 packets with a simulated processing workload.

| Workers | Average Processing Time | Speedup |
|---|---:|---:|
| 1 | 64.9 ms | 1.00x |
| 2 | 32.0 ms | 2.03x |
| 3 | 24.3 ms | 2.67x |
| 4 | 19.5 ms | 3.33x |

Using 4 workers reduced the processing time from about 64.9 ms to 19.5 ms.

## Example Output

```text
NETWORK PROCESSOR RESULTS
-------------------------
Packets Generated: 10000
Packets Processed: 9958
Packets Blocked:   42
Workers:           4
Processing Time:   19078 microseconds
Throughput:        521962 packets/second
Average Time:      1.91585 microseconds/packet
```

## Testing

I added tests to check that:

- Packets are routed to the correct ports
- Blocked packets are rejected
- Allowed packets pass through the filter
- Higher priority packets are processed before lower priority packets

## Built With

- C++
- CMake
- C++ threads and mutexes
- Git and GitHub

## How to Build

Create and enter the build folder:

```bash
mkdir build
cd build
```

Configure the project:

```bash
cmake .. -G "MinGW Makefiles"
```

Build it:

```bash
cmake --build .
```

Run the main program:

```bash
./network_processor
```

Run the tests:

```bash
./tests
```

## What I Learned

This project helped me learn more about C++ and how multithreading works. I also got practice using queues, mutexes, routing and filtering logic, performance testing, CMake, and Git.