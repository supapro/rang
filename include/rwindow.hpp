#ifndef __NWINDOW_HPP
#define __NWINDOW_HPP

#include "buffer.hpp"
#include "console_io.hpp"

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

#endif
