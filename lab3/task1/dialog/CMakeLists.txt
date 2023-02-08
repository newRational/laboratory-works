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
)

add_executable(dialog ${SOURCES} ${HEADERS})

include_directories(headers)
include_directories(../task/headers)

find_library(TASK_LIBRARY task ../task/cmake-build-debug)
target_link_libraries(dialog LINK_PUBLIC ${TASK_LIBRARY})