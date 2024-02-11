//
// Created by mick on 11.02.2024.
//

#ifndef MULTITHREADING_PROJECT_READER_H
#define MULTITHREADING_PROJECT_READER_H


#include "Buffer.h"

class Reader {
private:
    Buffer &queue;
    int experience;
public:
    Reader(Buffer &queue);

    [[noreturn]] void read();
};


#endif //MULTITHREADING_PROJECT_READER_H
