cmake_minimum_required(VERSION 3.28)
project(passm)

find_package(ftxui)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

file(GLOB_RECURSE SOURCES "src/**/*.cc")
file(GLOB_RECURSE HEADERS "include/**/*.h")

add_executable(passm src/main.cc ${SOURCES} ${HEADERS})

target_include_directories(passm PRIVATE include)

message(STATUS "CXX_FLAGS: ${CMAKE_CXX_FLAGS}")

target_link_libraries(
  passm
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)
