//
// Created by mick on 11.02.2024.
//

#include <random>
#include <iostream>
#include "../include/Writer.h"

Writer::Writer(Buffer &queue) : queue(queue) {
    Writer::experience = 0;
}

[[noreturn]] void Writer::write() {
    while (true) {
        queue.put(next());
        experience++;
    }
}

int Writer::next() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 100);
    return dist6(rng) % 100;
}
