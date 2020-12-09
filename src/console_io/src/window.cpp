#include "window.hpp"
#include <iostream>

window::window(int _size_x, int _size_y, int offset_x, int offset_y)
    : size_x(_size_x), size_y(_size_y)
{
        win_ptr = newwin(size_y, size_x, offset_y, offset_x);
        refresh();
}

window::~window()
{
        refresh();
        delwin(win_ptr);
}

void window::refresh()
{
        wrefresh(win_ptr);
}

void window::move(int x, int y)
{
        wmove(win_ptr, y, x);
}

void window::output(std::string s)
{
        waddstr(win_ptr, s.c_str());
}

void window::move_and_output(int x, int y, std::string s)
{
        mvwaddstr(win_ptr, y, x, s.c_str());
}
