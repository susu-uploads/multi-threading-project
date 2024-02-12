set(LIBRARY_NAME file-producer-consumer)
set(
        SOURCE_FILES
        src/util.cpp)
set(
        HEADER_FILES
        include/util.h)

add_library(${LIBRARY_NAME} STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(${LIBRARY_NAME} PUBLIC include)
