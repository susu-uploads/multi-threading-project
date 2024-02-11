//
// Created by mick on 11.02.2024.
//

#ifndef MULTITHREADING_PROJECT_WRITER_H
#define MULTITHREADING_PROJECT_WRITER_H


#include "AtomicQueue.h"

class Writer {
private:
    AtomicQueue &queue;
    int experience;

    static int next();

public:
    Writer(AtomicQueue &queue);

    [[noreturn]] void write();
};


#endif //MULTITHREADING_PROJECT_WRITER_H
