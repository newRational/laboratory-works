cmake_minimum_required(VERSION 3.22)
project(test)

set(CMAKE_CXX_STANDARD 17)

set(
        SOURCE_FILES

        main.cpp)

add_executable(
        test

        ${SOURCE_FILES}
)

include_directories(../task/headers)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

find_library(TASK_LIBRARY task ../task/lib)
target_link_libraries(test LINK_PUBLIC ${TASK_LIBRARY} gtest gtest_main)

