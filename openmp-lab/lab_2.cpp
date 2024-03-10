//
// Created by mick on 3/10/24.
//

#include <cstdio>
#include <omp.h>

int main() {
    int k;
    #pragma omp parallel default(none) shared(k)
    {
        k = omp_get_thread_num();
        if (k % 2 == 0) {
            printf("I am %d thread from %d threads!\n", k, omp_get_num_threads());
        }
    }
    return 0;
}