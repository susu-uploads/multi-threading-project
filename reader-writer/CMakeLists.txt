cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(PROJECT_NAME reader_writer)
set(
        SOURCE_FILES
        src/Reader.cpp
        src/Writer.cpp
        src/Buffer.cpp
        main.cpp)
set(
        HEADER_FILES
        include/Reader.h
        include/Writer.h
        include/Buffer.h)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})
