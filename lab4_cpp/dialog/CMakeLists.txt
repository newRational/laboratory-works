cmake_minimum_required(VERSION 3.22)
project(dialog)

set(CMAKE_CXX_STANDARD 17)

set(
        SOURCES
        sources/dialog.cpp
        sources/main.cpp
)

set(
        HEADERS
        headers/dialog.h
        headers/myVector.h
)

add_executable(dialog ${SOURCES} ${HEADERS})
add_executable(main sources/main.cpp)

include_directories(headers)
include_directories(../task/headers)
include_directories(../task/headers/habitations)
include_directories(../task/headers/addresses)

find_library(TASK_LIBRARY task ../task/cmake-build-debug)
target_link_libraries(dialog LINK_PUBLIC ${TASK_LIBRARY})