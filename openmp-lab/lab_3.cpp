//
// Created by mick on 3/10/24.
//

#include <cstdio>
#include <omp.h>
#include <unistd.h>

int main() {
    int rank;
    #pragma omp parallel default(none) shared(rank)
    {
        rank = omp_get_thread_num();
        sleep(1);
        printf("I am %d thread.\n", rank);
    }
    return 0;
}