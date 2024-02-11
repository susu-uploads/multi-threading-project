//
// Created by mick on 11.02.2024.
//

#include "Buffer.h"
#include <mutex>

using namespace std;

size_t q_size;
size_t q_capacity;

Buffer::Buffer(size_t capacity) {
    q_capacity = capacity;
    q_size = 0;
}

void Buffer::put(int number) {
    // Wait for buffer less than max
    if (q_size >= q_capacity) {
        unique_lock<mutex> lock(write_mutex);
        able_to_write.wait(
                lock,
                [] {
                    return (q_size < q_capacity);
                }
        );
    }

    // Critical buffer section
    m.lock();
    queue.push(number);
    q_size++;
    m.unlock();

    // Notify readers
    able_to_read.notify_one();
}

int Buffer::get() {
    int number;

    // Wait for buffer more than min
    if (q_size == 0) {
        unique_lock<mutex> lock(read_mutex);
        able_to_read.wait(
                lock,
                [] {
                    return (q_size != 0);
                }
        );
    }

    // Critical buffer section
    m.lock();
    number = queue.front();
    queue.pop();
    q_size--;
    m.unlock();

    // Notify writers
    able_to_write.notify_one();
    return number;
}
