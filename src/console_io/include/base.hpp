#ifndef __SCREEN_HPP
#define __SCREEN_HPP

#include "window.hpp"
#include <ncurses.h>

namespace console_io
{
class ncurses : public window
{
      public:
        ncurses();

        ~ncurses();
};
} // namespace console_io

#endif
