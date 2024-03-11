//
// Created by mick on 3/11/24.
//

#include <mpi.h>
#include <cstdio>

int main(int argc, char **argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);
    // Find out rank, size
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // We are assuming at least 2 processes for this task
    if (world_size < 2) {
        fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    int number;
    if (world_rank == 0) {
        number = 45;
        MPI_Send(
                /* buf          = */ &number,
                /* count        = */ 1,
                /* datatype     = */ MPI_INT,
                /* dest         = */ 1,
                /* tag          = */ 0,
                /* comm         = */ MPI_COMM_WORLD);
        printf("Process %d put number %d\n", world_rank, number);
    } else if (world_rank == 1) {
        MPI_Recv(
                /* buf          = */ &number,
                /* count        = */ 1,
                /* datatype     = */ MPI_INT,
                /* source       = */ 0,
                /* tag          = */ 0,
                /* comm         = */ MPI_COMM_WORLD,
                /* status       = */ MPI_STATUS_IGNORE);
        printf("Process %d received number %d\n", world_rank, number);
    }
    MPI_Finalize();
}