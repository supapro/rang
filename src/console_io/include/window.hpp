#ifndef __WINDOW_HPP
#define __WINDOW_HPP

#include <memory>
#include <ncurses.h>
#include <string>
#include <vector>

namespace console_io
{
class window
{
      protected:
        WINDOW *win_ptr = nullptr;

      public:
        int size_x     = 0;
        int size_y     = 0;
        window *parent = nullptr;
        std::vector<window> subwindows;

        window() = default;

        window(int _size_x, int _size_y, int offset_x, int offset_y, window *_parent = nullptr);

        ~window();

        bool operator==(const window &other);

        void refresh();

        void move(int x, int y);

        void output(std::string s);

        void move_and_output(int x, int y, std::string s);

        window subwindow(int _size_x, int _size_y, int offset_x, int offset_y);
};
} // namespace console_io

#endif
