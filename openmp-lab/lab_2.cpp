//
// Created by mick on 3/10/24.
//

#include <cstdio>
#include <omp.h>

void print_all(int k) {
    k = omp_get_thread_num();
    printf("I am %d thread from %d threads!\n", k, omp_get_num_threads());
}

void print_even(int k) {
    k = omp_get_thread_num();
    if (k % 2 == 0) {
        printf("I am %d thread from %d threads!\n", k, omp_get_num_threads());
    }
}

int main() {
    int k;
    #pragma omp parallel default(none) shared(k)
    {
        k = omp_get_thread_num();
        print_even(k);
    }
    return 0;
}