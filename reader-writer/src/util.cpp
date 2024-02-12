//
// Created by mick on 12.02.2024.
//

#include <thread>
#include <Buffer.h>
#include <Writer.h>
#include <Reader.h>

using namespace std;
using namespace chrono_literals;

void reader_writer_simulate() {
    auto queue = Buffer{};
    auto w1 = Writer{queue};
    auto w2 = Writer{queue};
    auto r1 = Reader{queue};

    // Init writers
    thread t1(&Writer::write, &w1);
    thread t2(&Writer::write, &w2);
    // Optional sleep in order for buffer to fill
    this_thread::sleep_for(1000ms);

    // Init reader
    thread t3(&Reader::read, &r1);

    t1.join();
    t2.join();
    t3.join();
}
