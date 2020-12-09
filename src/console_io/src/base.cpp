#include "base.hpp"
#include <algorithm>

using namespace console_io;

ncurses::ncurses()
{
        win_ptr = initscr();
}

ncurses::~ncurses()
{
        if (win_ptr == stdscr) { // guarantee Liskov substitution
                endwin();
        } else {
                if (parent != nullptr) {
                        parent->subwindows.erase(
                            std::find(parent->subwindows.begin(), parent->subwindows.end(), *this));
                }
                delwin(win_ptr);
        }
}
