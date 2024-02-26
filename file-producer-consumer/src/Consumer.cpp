//
// Created by mick on 2/17/24.
//

#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>
#include <semaphore>
#include "../include/Consumer.h"
#include "../include/Message.h"

using namespace std;

void Consumer::consume() {
    // Wait for producer
    sem_t *sem = sem_open(sh_sem_name, O_CREAT, 0644, 0);
    sem_wait(sem);

    // Get access to shared memory
    int shmFd = shm_open(sh_mem_name, O_RDWR, S_IRUSR | S_IWUSR);
    ftruncate(shmFd, sizeof(Message));
    auto *msg_ptr = (Message*)mmap(nullptr, sizeof(Message), PROT_READ | PROT_WRITE, MAP_SHARED, shmFd, 0);

    // Read from shared memory
    pid_t curr_pid = getpid();
    cout << "Process " << curr_pid << ": "
         << "receive [" << msg_ptr->value << "] "
         << "from PID " << msg_ptr->pid << '\n';

    close(shmFd);
    sem_destroy(sem);
}

Consumer::Consumer(const char *s, const char *p) : sh_sem_name(s), sh_mem_name(p) {}

