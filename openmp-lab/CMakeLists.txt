cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(PROJECT_NAME openmp_lab)
set(
        SOURCE_FILES
        lab_1.cpp
        lab_2.cpp
        lab_3.cpp
        lab_4.cpp)

project(${PROJECT_NAME})

foreach (X IN LISTS SOURCE_FILES)
    set(NAME ${PROJECT_NAME}_${X})
    add_executable(${NAME} ${X})
    message(STATUS "${NAME} built successfully")
endforeach ()

find_package(OpenMP)
if (OpenMP_CXX_FOUND)
    foreach (X IN LISTS SOURCE_FILES)
        set(NAME ${PROJECT_NAME}_${X})
        target_link_libraries(${NAME} PUBLIC OpenMP::OpenMP_CXX)
        message(STATUS "${NAME} open-mp'ed successfully")
    endforeach ()
endif ()