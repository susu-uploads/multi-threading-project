//
// Created by mick on 3/10/24.
//

#include <cstdio>
#include <omp.h>

int main() {
    int rank = -1;
    #pragma omp parallel default(none) private(rank)
    {
        rank = omp_get_thread_num();
        printf("I am %d thread.\n", rank);
    }
    printf("Rank is %d", rank);
    return 0;
}