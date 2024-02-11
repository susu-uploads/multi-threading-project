//
// Created by mick on 11.02.2024.
//

#ifndef MULTITHREADING_PROJECT_READER_H
#define MULTITHREADING_PROJECT_READER_H


#include "AtomicQueue.h"

class Reader {
private:
    AtomicQueue &queue;
    int experience;
public:
    Reader(AtomicQueue &queue);

    [[noreturn]] void read();
};


#endif //MULTITHREADING_PROJECT_READER_H
