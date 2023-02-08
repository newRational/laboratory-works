cmake_minimum_required(VERSION 3.0)
project(task)

set(CMAKE_CXX_STANDARD 17)

set(
        SOURCES

        sources/addresses/Address.cpp
        sources/addresses/FlatAddress.cpp

        sources/habitations/Habitations.cpp
        sources/habitations/Apartment.cpp
        sources/habitations/Flat.cpp

        sources/Room.cpp
        sources/Building.cpp
        sources/habitations/Cottage.cpp
)

set (
        HEADERS

        headers/addresses/Address.h
        headers/addresses/FlatAddress.h

        headers/habitations/Habitation.h
        headers/habitations/Flat.h
        headers/habitations/Apartment.h
        headers/habitations/Cottage.h

        headers/Room.h
        headers/Building.h
        headers/TableElement.h
)

include_directories(headers)
include_directories(headers/addresses)
include_directories(headers/habitations)

add_library(task STATIC ${HEADERS} ${SOURCES})
