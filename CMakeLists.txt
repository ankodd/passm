cmake_minimum_required(VERSION 3.28)
project(passm)

set(CMAKE_CXX_STANDARD 20)

add_executable(
  passm
  src/main.cc
  include/menu.h
  include/user.h
  include/pass_utils.h
  include/serializer.h
  src/menu.cc
  src/user.cc
  src/serializer.cc)
