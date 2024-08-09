cmake_minimum_required(VERSION 3.28)
project(passm)

set(CMAKE_CXX_STANDARD 20)

add_executable(
  passm
  src/main.cc
  include/menu.h
        include/user_entry.h
  include/pass_utils.h
  include/binary_serialize.h
  include/entry.h
  include/category.h
  include/sys_utils.h
  src/menu.cc
        src/user_entry.cc
  src/entry.cc
  src/binary_serialize.cc
        include/passwd_entry.h
        src/passwd_entry.cc

)
