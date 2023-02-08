cmake_minimum_required(VERSION 3.22)
project(externalCodeApp)

set(CMAKE_CXX_STANDARD 17)

set(
        SOURCES

        sources/AccountsService.cpp
        sources/Cipher.cpp
        sources/CaesarCipher.cpp
        sources/main.cpp
)

set(
        HEADERS

        headers/AccountsService.h
        headers/Cipher.h
        headers/CaesarCipher.h)

include_directories(../../external_code/Table_dynamic/Table_dynamic/Table_lib)
include_directories(headers)

add_executable(
        externalCodeApp

        ${SOURCES}
        ${HEADERS}
)