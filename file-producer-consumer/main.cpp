//
// Created by mick on 2/17/24.
//

#include <unistd.h>
#include "include/Producer.h"
#include "include/Consumer.h"

#define SHARED_OBJ_NAME "/sh_mem"
#define SHARED_SEM_NAME "/sh_sem"

int main() {
    pid_t pid = fork();

    // PARENT PROCESS
    if (pid != 0) {
        auto consumer = Consumer(SHARED_SEM_NAME, SHARED_OBJ_NAME);
        consumer.consume();
    }
    // CHILD PROCESS
    else {
        auto producer = Producer(SHARED_SEM_NAME, SHARED_OBJ_NAME);
        producer.produce();
    }
    return 0;
}
