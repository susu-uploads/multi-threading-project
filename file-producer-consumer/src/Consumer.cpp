//
// Created by mick on 2/17/24.
//

#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>
#include "../include/Consumer.h"
#include "../include/Message.h"

using namespace std;

Consumer::Consumer(binary_semaphore *semaphore, const char *path) : able_to_consume(semaphore), shm_path(path) {}

void Consumer::consume() {
    // Get access to shared memory
    int shmFd = shm_open(shm_path, O_RDWR, S_IRUSR | S_IWUSR);
    ftruncate(shmFd, sizeof(Message));
    auto *msg_ptr = (Message *) mmap(nullptr, sizeof(Message), PROT_READ | PROT_WRITE, MAP_SHARED, shmFd, 0);

    // Read from shared memory
    able_to_consume->acquire();
    pid_t curr_pid = getpid();
    cout << "Process " << curr_pid << ": " <<
         "Receive [" << msg_ptr->payload << "] " << "from PID " << msg_ptr->pid << '\n';
    close(shmFd);
}
