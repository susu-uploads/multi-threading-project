//
// Created by mick on 11.02.2024.
//

#include "Buffer.h"

using namespace std;


void Buffer::put(int number) {
    empty_cells.acquire();
    mlock.lock();
    storage.push(number);
    mlock.unlock();
    filled_cells.release();
}

int Buffer::get() {
    int number;
    filled_cells.acquire();
    mlock.lock();
    number = storage.front();
    storage.pop();
    mlock.unlock();
    empty_cells.release();
    return number;
}
