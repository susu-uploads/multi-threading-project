//
// Created by mick on 12.02.2024.
//

#include <thread>
#include <AtomicQueue.h>
#include <Writer.h>
#include <Reader.h>

using namespace std;
using namespace chrono_literals;

const std::size_t QUEUE_SIZE = 10;

void reader_writer_simulate() {
    auto queue = AtomicQueue{QUEUE_SIZE};
    auto w1 = Writer{queue};
    auto w2 = Writer{queue};
    auto r1 = Reader{queue};

    // Init readers
    thread t1(&Writer::write, &w1);
    thread t2(&Writer::write, &w2);
    // Optional sleep in order buffer to fill
    // this_thread::sleep_for(1000ms);

    // Init writer
    thread t3(&Reader::read, &r1);

    t1.join();
    t2.join();
    t3.join();
}
