cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)
set(PROJECT_NAME multithreading_project)
set(
        SOURCE_FILES
        main.cpp
)

project(${PROJECT_NAME})

add_subdirectory(reader-writer)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC reader-writer)