//
// Created by mick on 11.02.2024.
//

#ifndef MULTITHREADING_PROJECT_BUFFER_H
#define MULTITHREADING_PROJECT_BUFFER_H

#include <mutex>
#include <semaphore>
#include <queue>
#include <condition_variable>

const int BUFFER_SIZE = 10;

class Buffer {
private:
    std::mutex mlock;
    std::counting_semaphore<BUFFER_SIZE> empty_cells{BUFFER_SIZE};
    std::counting_semaphore<BUFFER_SIZE> filled_cells{0};
    std::queue<int> storage;
public:
    void put(int number);

    int get();
};


#endif //MULTITHREADING_PROJECT_BUFFER_H
