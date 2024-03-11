cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(PROJECT_NAME mpi_lab)
set(
        SOURCE_FILES
        lab_14.cpp
        lab_15.cpp)

project(${PROJECT_NAME})

foreach (X IN LISTS SOURCE_FILES)
    set(NAME ${PROJECT_NAME}_${X})
    add_executable(${NAME} ${X})
    message(STATUS "${NAME} built successfully")
endforeach ()

find_package(MPI)
include_directories(SYSTEM ${MPI_INCLUDE_PATH})
if (MPI_CXX_FOUND)
    foreach (X IN LISTS SOURCE_FILES)
        set(NAME ${PROJECT_NAME}_${X})
        target_link_libraries(${NAME} PUBLIC MPI::MPI_CXX)
        message(STATUS "${NAME} mpi'd successfully")
    endforeach ()
endif ()