//
// Created by mick on 2/17/24.
//

#include <fcntl.h>
#include <sys/mman.h>
#include "../include/Producer.h"
#include "../include/Message.h"

Producer::Producer(std::binary_semaphore *semaphore, const char *path) : able_to_produce(semaphore), shm_path(path) {}

void Producer::produce() {
    // Get access to shared memory
    int shmFd = shm_open(shm_path, O_RDWR, S_IRUSR | S_IWUSR);
    ftruncate(shmFd, sizeof(Message));
    auto *msg_ptr = (Message *) mmap(nullptr, sizeof(Message), PROT_READ | PROT_WRITE, MAP_SHARED, shmFd, 0);

    // Write into shared memory
    msg_ptr->pid = getpid();
    msg_ptr->payload = "Blin s Zhulienom";
    munmap(msg_ptr, sizeof(Message));
    close(shmFd);
    able_to_produce->release();
}
