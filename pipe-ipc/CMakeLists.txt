cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(PROJECT_NAME pipe_ipc)
set(
        SOURCE_FILES
        main.cpp
        src/ProduceService.cpp
        src/ConsumeService.cpp)
set(
        HEADER_FILES
        include/ProduceService.h
        include/ConsumeService.h)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})
