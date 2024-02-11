//
// Created by mick on 11.02.2024.
//

#ifndef MULTITHREADING_PROJECT_BUFFER_H
#define MULTITHREADING_PROJECT_BUFFER_H

#include <mutex>
#include <queue>
#include <condition_variable>


class Buffer {
private:
    std::mutex m;
    std::queue<int> queue;
    std::mutex read_mutex;
    std::mutex write_mutex;
    std::condition_variable able_to_read;
    std::condition_variable able_to_write;
public:
    explicit Buffer(std::size_t capacity);

    void put(int number);

    int get();
};


#endif //MULTITHREADING_PROJECT_BUFFER_H
