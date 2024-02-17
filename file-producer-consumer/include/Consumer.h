//
// Created by mick on 2/17/24.
//

#ifndef FILE_PRODUCER_CONSUMER_CONSUMER_H
#define FILE_PRODUCER_CONSUMER_CONSUMER_H

#include <semaphore>

class Consumer {
private:
    std::binary_semaphore *able_to_consume;
    const char *shm_path;
public:
    explicit Consumer(std::binary_semaphore *semaphore, const char *path);

    void consume();
};


#endif //FILE_PRODUCER_CONSUMER_CONSUMER_H
