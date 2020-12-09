#ifndef __WINDOW_HPP
#define __WINDOW_HPP

#include <ncurses.h>
#include <string>

class window
{
      private:
        WINDOW *win_ptr;

      public:
        int size_x;
        int size_y;

        window(int _size_x, int _size_y, int offset_x, int offset_y);

        ~window();

        void refresh();

        void move(int x, int y);

        void output(std::string s);

        void move_and_output(int x, int y, std::string s);
};

#endif
