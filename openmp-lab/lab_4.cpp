//
// Created by mick on 3/10/24.
//

#include <cstdio>
#include <omp.h>

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

void omp_for(int *sum, int N, int threads) {
    int v_sum = 0;

    #pragma omp parallel reduction(+:v_sum) shared(N) default(none) num_threads(threads)
    {
        #pragma omp for
        for (int i = 1; i < N; ++i) {
            v_sum += i;
        }
        printf("[%d]: Sum = %d\n", omp_get_thread_num(), v_sum);
    }
    *sum = v_sum;
}

void omp_if(int *sum, int N, int threads) {
    int v_sum = 0;
    int v_threads = min(N, threads);

    #pragma omp parallel reduction(+:v_sum) shared(N) default(none) num_threads(v_threads)
    {
        const int rank = omp_get_thread_num();
        const int section_size = N / omp_get_num_threads();
        int end;

        int start = section_size * rank;
        if (rank == omp_get_num_threads() - 1) {
            end = N;
        } else {
            end = start + section_size;
        }
        for (int i = start; i < end; ++i) {
            v_sum += i;
        }
        printf("[%d]: Sum = %d\n", omp_get_thread_num(), v_sum);
    }
    *sum = v_sum;
}

int main() {
    int sum;
    omp_if(&sum, 10, 2);
    printf("Sum = %d", sum);
    return 0;
}