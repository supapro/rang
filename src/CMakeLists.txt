add_subdirectory(console_io)

add_executable (rang evloop.cpp buffer.cpp rwindow.cpp rang.cpp)

find_package(Boost 1.70.0 REQUIRED COMPONENTS system thread)

target_compile_features(rang PUBLIC cxx_std_17)
target_include_directories(rang PUBLIC ${CURSES_INCLUDE_DIRS})
target_link_libraries(rang PUBLIC ${CURSES_LIBRARIES} ${Boost_LIBRARIES} console_io)
