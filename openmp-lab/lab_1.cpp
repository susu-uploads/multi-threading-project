//
// Created by mick on 3/10/24.
//

#include <cstdio>
#include <omp.h>

int main() {
    omp_set_num_threads(4);
    #pragma omp parallel default(none) num_threads(4)
    {
        printf("Hello world!\n");
    }
    return 0;
}