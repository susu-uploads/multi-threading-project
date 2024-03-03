//
// Created by mick on 3/3/24.
//
#include <unistd.h>
#include <cstdlib>
#include "include/ConsumeService.h"
#include "include/ProduceService.h"


int main() {
    int pipe_fds[2];
    if (pipe(pipe_fds) < 0)
        exit(EXIT_FAILURE);

    pid_t pid = fork();

    // PARENT PROCESS
    if (pid != 0) {
        auto consumer = ConsumeService(pipe_fds);
        consumer.init();
    }
    // CHILD PROCESS
    else {
        auto producer = ProduceService(pipe_fds);
        producer.init(10, 1, 2);
    }
    return 0;
}