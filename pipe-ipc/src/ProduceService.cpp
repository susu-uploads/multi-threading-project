//
// Created by mick on 3/3/24.
//

#include <cstdio>
#include <unistd.h>
#include "../include/ProduceService.h"

#define MESSAGE_SIZE 7

const char message[MESSAGE_SIZE] = "Hello!";

ProduceService::ProduceService(const int *ptr_fd) {
    reader_fd = ptr_fd[0];
    writer_fd = ptr_fd[1];
}

void ProduceService::init(int times, int delay, int init_delay) const {
    close(reader_fd);
    sleep(init_delay);
    while (times-- > 0) {
        write(writer_fd, message, MESSAGE_SIZE);
        sleep(delay);
    }
    close(writer_fd);
}

