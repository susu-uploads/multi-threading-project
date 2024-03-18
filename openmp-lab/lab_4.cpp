//
// Created by mick on 3/10/24.
//

#include <cstdio>
#include <omp.h>

int main() {
    int sum = 0;
    int N = 10;

    #pragma omp parallel reduction(+:sum) default(none) shared(N)
    {
        #pragma omp for
        for (int i = 1; i < N; ++i) {
            sum += i;
        }
        printf("[%d]: Sum = %d\n", omp_get_thread_num(), sum);
    }
    printf("Sum = %d", sum);
    return 0;
}