cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(PROJECT_NAME file_producer_consumer)
set(
        SOURCE_FILES
        main.cpp
        src/Producer.cpp
        src/Consumer.cpp)
set(
        HEADER_FILES
        include/Producer.h
        include/Consumer.h include/Message.h)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})
