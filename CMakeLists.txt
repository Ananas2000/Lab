cmake_minimum_required(VERSION 3.28.1)
project(laba)

set(CMAKE_C_StANDARD 11)

add_executable(laba main.c)

add_subdirectory(libs)
target_link_libraries(laba data_structures)
target_link_libraries(laba algorithms)