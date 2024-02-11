//
// Created by mick on 11.02.2024.
//

#ifndef MULTITHREADING_PROJECT_WRITER_H
#define MULTITHREADING_PROJECT_WRITER_H


#include "Buffer.h"

class Writer {
private:
    Buffer &queue;
    int experience;

    static int next();

public:
    Writer(Buffer &queue);

    [[noreturn]] void write();
};


#endif //MULTITHREADING_PROJECT_WRITER_H
