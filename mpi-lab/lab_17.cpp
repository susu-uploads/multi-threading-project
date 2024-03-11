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

    if (world_size < 2) {
        fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    int number;
    int from = ((world_rank - 1) + world_size) % world_size;
    int to = (world_rank + 1) % world_size;
    if (world_rank == 0) {
        number = 0;
        MPI_Send(
                /* buf          = */ &number,
                /* count        = */ 1,
                /* datatype     = */ MPI_INT,
                /* dest         = */ to,
                /* tag          = */ 0,
                /* comm         = */ MPI_COMM_WORLD);
        MPI_Recv(
                /* buf          = */ &number,
                /* count        = */ 1,
                /* datatype     = */ MPI_INT,
                /* source       = */ from,
                /* tag          = */ 0,
                /* comm         = */ MPI_COMM_WORLD,
                /* status       = */ MPI_STATUS_IGNORE);
        printf("[%d]: receive message %d\n", world_rank, number);
    } else {
        MPI_Recv(
                /* buf          = */ &number,
                /* count        = */ 1,
                /* datatype     = */ MPI_INT,
                /* source       = */ from,
                /* tag          = */ 0,
                /* comm         = */ MPI_COMM_WORLD,
                /* status       = */ MPI_STATUS_IGNORE);
        printf("[%d]: receive message %d\n", world_rank, number);
        number++;
        MPI_Send(
                /* buf          = */ &number,
                /* count        = */ 1,
                /* datatype     = */ MPI_INT,
                /* dest         = */ to,
                /* tag          = */ 0,
                /* comm         = */ MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}