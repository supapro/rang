cmake_minimum_required(VERSION 3.14)
project(rang)

add_subdirectory(src)
target_include_directories(rang PRIVATE include)
