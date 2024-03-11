//
// Created by mick on 3/11/24.
//

#include <mpi.h>

int total, iam;

int main() {
    MPI_Init(nullptr, nullptr);
    MPI_Comm_size(MPI_COMM_WORLD, &total);
    MPI_Comm_rank(MPI_COMM_WORLD, &iam);
    printf("Привет! Я %d-й процесс из %d.\n", iam, total);
    MPI_Finalize();
    return 0;
}