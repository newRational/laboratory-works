cmake_minimum_required(VERSION 3.22)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

set(
        SOURCE_FILES

        sources/main.cpp
        sources/dialog.cpp
)

add_executable(
        lab2

        ${SOURCE_FILES}
)

include_directories(../task/headers)

find_library(TASK_LIBRARY task ../task/lib)
target_link_libraries(lab2 LINK_PUBLIC ${TASK_LIBRARY})
