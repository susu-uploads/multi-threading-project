//
// Created by mick on 2/17/24.
//

#ifndef FILE_PRODUCER_CONSUMER_PRODUCER_H
#define FILE_PRODUCER_CONSUMER_PRODUCER_H


#include <semaphore>

class Producer {
private:
    std::binary_semaphore *able_to_produce;
    const char *shm_path;
public:
    explicit Producer(std::binary_semaphore *semaphore, const char *path);

    void produce();
};


#endif //FILE_PRODUCER_CONSUMER_PRODUCER_H
