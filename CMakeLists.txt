cmake_minimum_required(VERSION 3.28)
project(passm)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES "src/**/*.cc")
file(GLOB_RECURSE HEADERS "include/**/*.h")

add_executable(passm src/main.cc ${SOURCES} ${HEADERS})

target_include_directories(passm PRIVATE include)
