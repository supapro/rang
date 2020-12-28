#include "window.hpp"
#include <algorithm>

using namespace console_io;

window::window(int _size_x, int _size_y, int offset_x, int offset_y, window *_parent)
    : size_x(_size_x), size_y(_size_y), parent(_parent)
{
        win_ptr = newwin(size_y, size_x, offset_y, offset_x);
        if (win_ptr == nullptr) {
                throw 1; // TODO errors
        }
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

bool window::operator==(const window &other) const
{
        return win_ptr == other.win_ptr;
}

int window::get_size_x() const
{
        return size_x;
}

int window::get_size_y() const
{
        return size_y;
}

int window::get_offset_x() const
{
        return offset_x;
}

int window::get_offset_y() const
{
        return offset_y;
}

void window::refresh() const
{
        if (wrefresh(win_ptr) == ERR) {
                throw 1;
        };
}

void window::move(int x, int y) const
{
        if (wmove(win_ptr, y, x) == ERR) {
                throw 1;
        };
}

void window::output(std::string s) const
{
        if (waddstr(win_ptr, s.c_str()) == ERR) {
                throw 1;
        }
}

void window::move_and_output(int x, int y, std::string s) const
{
        if (mvwaddstr(win_ptr, y, x, s.c_str()) == ERR) {
                throw 1;
        }
}

void window::outputln(int y, std::string s) const
{
        s.resize(size_x - 1, ' ');
        if (mvwaddstr(win_ptr, y, 0, s.c_str()) == ERR) {
                throw 1;
        }
}

window window::subwindow(int _size_x, int _size_y, int offset_x, int offset_y)
{
        window result;
        result.win_ptr = subwin(win_ptr, _size_y, _size_x, offset_y, offset_x);
        if (result.win_ptr == nullptr) {
                throw 1;
        }
        result.size_x = _size_x;
        result.size_y = _size_y;
        subwindows.push_back(result);
        return result;
}
