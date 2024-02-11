//
// Created by mick on 11.02.2024.
//

#include <iostream>
#include "../include/Reader.h"

Reader::Reader(Buffer &queue) : queue(queue) {
    Reader::experience = 0;
}

[[noreturn]] void Reader::read() {
    while (true) {
        auto number = queue.get();
        std::cout << number << ' ' << "exp: " << experience++ << '\n';
    }
}
