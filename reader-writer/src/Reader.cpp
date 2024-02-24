//
// Created by mick on 11.02.2024.
//

#include "../include/Reader.h"

using namespace std;
using namespace chrono_literals;

const char *const OUTPUT_TEMPLATE = "From reader [%lu] -> %d | Count [%d]\n";

Reader::Reader(Buffer &queue) : queue(queue) {
    Reader::experience = 0;
}

[[noreturn]] void Reader::read() {
    while (true) {
        this_thread::sleep_for(1000ms);
        auto number = queue.get();
        auto thread_id = std::hash<std::thread::id>{}(std::this_thread::get_id());
        printf(OUTPUT_TEMPLATE, thread_id, number, experience++);
    }
}
