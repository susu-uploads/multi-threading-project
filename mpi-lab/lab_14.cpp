//
// Created by mick on 3/11/24.
//

#include <mpi.h>

int main() {
    // Initialize the MPI environment
    MPI_Init(nullptr, nullptr);
    // Find out rank, size
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    printf("Hello! I am %d process from %d processes!\n", world_rank, world_size);
    MPI_Finalize();
    return 0;
}