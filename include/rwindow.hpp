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
        window(console_io::window &&_win, buffer &_tied_buf);

        void refresh();

        void shift_viewport(int shift);
};

#endif
