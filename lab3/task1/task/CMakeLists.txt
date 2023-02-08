cmake_minimum_required(VERSION 3.22)
project(task)

set(CMAKE_CXX_STANDARD 17)

set(
        SOURCES
        sources/Element.cpp
        sources/Diagram.cpp
)

set(
        HEADERS
        headers/Element.h
        headers/Diagram.h
)

include_directories(headers)

add_library(
        task
        ${SOURCES}
        ${HEADERS}
)
