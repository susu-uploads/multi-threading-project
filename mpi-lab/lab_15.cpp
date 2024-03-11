//
// Created by mick on 3/11/24.
//

#include <mpi.h>
#include <cstdio>

int main() {
    // Initialize the MPI environment
    MPI_Init(nullptr, nullptr);
    // Find out rank, size
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    if (world_rank == 0) {
        printf("%d processes\n", world_size);
    } else if (world_rank % 2 == 0) {
        printf("I am %d process: FIRST\n", world_rank);
    } else {
        printf("I am %d process: SECOND\n", world_rank);
    }

    MPI_Finalize();
    return 0;
}