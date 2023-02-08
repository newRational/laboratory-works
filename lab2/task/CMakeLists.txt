cmake_minimum_required(VERSION 3.22)
project(task)

set(CMAKE_CXX_STANDARD 17)

set(
        HEADER_FILES

        headers/Tractrix.h
        headers/Point.h
)

set(
        SOURCE_FILES

        sources/Tractrix.cpp
        sources/Point.cpp
)

add_library(
        task

        STATIC

        ${SOURCE_FILES}
        ${HEADER_FILES}
)

add_executable(
        main

        ${SOURCE_FILES}
)
