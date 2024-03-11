/home/mick/opt/clion-2020.3.4/bin/cmake/linux/bin/cmake --build ./cmake-build-debug --target mpi_lab_lab_16.cpp -- -j 4
mpiexec -n 2 ./cmake-build-debug/mpi_lab_lab_16.cpp
