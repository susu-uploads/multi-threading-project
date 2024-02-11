set(LIBRARY_NAME reader-writer)
set(
        SOURCE_FILES
        src/Reader.cpp
        src/Writer.cpp
        src/util.cpp
        src/Buffer.cpp
        src/util.cpp)
set(
        HEADER_FILES
        include/Reader.h
        include/Writer.h
        include/util.h
        include/Buffer.h)

add_library(${LIBRARY_NAME} STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(${LIBRARY_NAME} PUBLIC include)
