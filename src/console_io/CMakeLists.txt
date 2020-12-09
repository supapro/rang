cmake_minimum_required(VERSION 3.17)
project(console_io)

add_library(console_io OBJECT src/window.cpp)

target_include_directories(console_io PUBLIC include)
