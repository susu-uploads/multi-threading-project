//
// Created by mick on 3/11/24.
//

#include <mpi.h>

int total, rank;

int main() {
    MPI_Init(nullptr, nullptr);
    MPI_Comm_size(MPI_COMM_WORLD, &total);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        printf("%d processes\n", total);
    } else if (rank % 2 == 0) {
        printf("I am %d process: FIRST\n", rank);
    } else {
        printf("I am %d process: SECOND\n", rank);
    }

    MPI_Finalize();
    return 0;
}