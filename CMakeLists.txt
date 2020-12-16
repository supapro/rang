cmake_minimum_required(VERSION 3.17)
project(rang)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)

add_subdirectory(src)

target_include_directories(rang PUBLIC include)
