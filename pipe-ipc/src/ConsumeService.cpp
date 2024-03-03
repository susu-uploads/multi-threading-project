//
// Created by mick on 3/3/24.
//

#include <cstdio>
#include <unistd.h>
#include <cstdlib>
#include "../include/ConsumeService.h"

#define MESSAGE_SIZE 7

char input_buffer[MESSAGE_SIZE];

ConsumeService::ConsumeService(const int *ptr_fd) {
    reader_fd = ptr_fd[0];
    writer_fd = ptr_fd[1];
}

void ConsumeService::init() const {
    close(writer_fd);
    int read_bytes;
    while ((read_bytes = read(reader_fd, input_buffer, MESSAGE_SIZE)) > 0) {
        printf("%s\n", input_buffer);
    }
    if (read_bytes != 0) {
        exit(EXIT_FAILURE);
    }
    close(reader_fd);
}
