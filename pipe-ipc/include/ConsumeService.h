//
// Created by mick on 3/3/24.
//

#ifndef PIPE_IPC_CONSUMESERVICE_H
#define PIPE_IPC_CONSUMESERVICE_H


class ConsumeService {
    int reader_fd;
    int writer_fd;
public:
    ConsumeService(const int *ptr_fd);

    void init() const;
};


#endif //PIPE_IPC_CONSUMESERVICE_H
