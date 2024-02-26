//
// Created by mick on 2/17/24.
//

#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>
#include <semaphore>
#include "../include/Producer.h"
#include "../include/Message.h"


void Producer::produce() {
    // Get access to shared memory
    int shmFd = shm_open(sh_m, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    ftruncate(shmFd, sizeof(Message));
    auto *msg_ptr = (Message *) mmap(nullptr, sizeof(Message), PROT_READ | PROT_WRITE, MAP_SHARED, shmFd, 0);

    // Write into shared memory
    msg_ptr->pid = getpid();
    msg_ptr->value = 10;
    munmap(msg_ptr, sizeof(Message));
    close(shmFd);

    // Optional wait
    sleep(0);

    // Notify consumer
    sem_t *sem = sem_open(sh_s, O_CREAT, 0644, 0);
    sem_post(sem);
}

Producer::Producer(const char *s, const char *p) : sh_s(s), sh_m(p) {}

