//
// Created by mick on 3/3/24.
//

#ifndef PIPE_IPC_PRODUCESERVICE_H
#define PIPE_IPC_PRODUCESERVICE_H


class ProduceService {
    int reader_fd;
    int writer_fd;
public:
    ProduceService(const int *ptr_fd);

    void init(int times, int delay, int init_delay = 0) const;
};


#endif //PIPE_IPC_PRODUCESERVICE_H
