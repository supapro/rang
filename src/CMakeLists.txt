add_subdirectory(console_io)

add_executable (rang rang.cpp buffer.cpp rwindow.cpp)

target_include_directories(rang PUBLIC ${CURSES_INCLUDE_DIRS})
target_link_libraries(rang PUBLIC ${CURSES_LIBRARIES} console_io)
