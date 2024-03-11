//
// Created by mick on 3/11/24.
//

#include <mpi.h>

int total, iam;

int main() {
    MPI_Init(nullptr, nullptr);
    MPI_Comm_size(MPI_COMM_WORLD, &total);
    MPI_Comm_rank(MPI_COMM_WORLD, &iam);
    printf("Hello! I am %d process from %d processes!\n", iam, total);
    MPI_Finalize();
    return 0;
}