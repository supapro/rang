#include "window.hpp"
#include <algorithm>

using namespace console_io;

window::window(int _size_x, int _size_y, int offset_x, int offset_y, window *_parent)
    : size_x(_size_x), size_y(_size_y), parent(_parent)
{
        win_ptr = newwin(size_y, size_x, offset_y, offset_x);
        refresh();
}

window::~window()
{
        if (parent != nullptr) {
                // this window must be deleted from parent's subwindows in order to avoid double
                // destruction
                parent->subwindows.erase(
                    std::find(parent->subwindows.begin(), parent->subwindows.end(), *this));
        }
        subwindows.clear();
        delwin(win_ptr);
}

bool window::operator==(const window &other)
{
        return win_ptr == other.win_ptr;
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

window window::subwindow(int _size_x, int _size_y, int offset_x, int offset_y)
{
        window result;
        result.win_ptr = subwin(win_ptr, _size_y, _size_x, offset_y, offset_x);
        result.size_x  = _size_x;
        result.size_y  = _size_y;
        subwindows.push_back(result);
        return result;
}
