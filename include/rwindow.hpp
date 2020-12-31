#ifndef __RWINDOW_HPP
#define __RWINDOW_HPP

#include "buffer.hpp"
#include "console_io.hpp"

namespace rang
{
class window
{
      private:
        console_io::window win;
        buffer &tied_buf;

      public:
        int offset_x = 0, offset_y = 0;
        window(console_io::window &&_win, buffer &_tied_buf);

        void refresh();

        void scroll_viewport(int shift);
};
} // namespace rang

#endif
