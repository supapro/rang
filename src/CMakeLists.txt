add_executable (rang rang.cpp)

target_include_directories(rang PUBLIC ${CURSES_INCLUDE_DIRS})
target_link_libraries(rang PUBLIC ${CURSES_LIBRARIES})
