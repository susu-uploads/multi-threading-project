//
// Created by mick on 11.02.2024.
//

#include <random>
#include "../include/Writer.h"

using namespace std;
using namespace chrono_literals;

const char *const OUTPUT_TEMPLATE = "From writer [%lu] -> %d | Count [%d]\n";

Writer::Writer(Buffer &queue) : queue(queue) {
    Writer::experience = 0;
}

[[noreturn]] void Writer::write() {
    while (true) {
        this_thread::sleep_for(1000ms);
        auto message = next();
        queue.put(message);
        auto thread_id = std::hash<std::thread::id>{}(std::this_thread::get_id());
        printf(OUTPUT_TEMPLATE, thread_id, message, experience++);
    }
}

int Writer::next() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 100);
    return dist6(rng) % 100;
}
