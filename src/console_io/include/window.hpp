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
        int size_x      = 0;
        int size_y      = 0;
        int offset_x    = 0;
        int offset_y    = 0;

      public:
        window *parent = nullptr;
        std::vector<window> subwindows;

        window() = default;

        window(int _size_x, int _size_y, int _offset_x, int _offset_y, window *_parent = nullptr);

        ~window();

        bool operator==(const window &other) const;

        int get_size_x() const;
        int get_size_y() const;
        int get_offset_x() const;
        int get_offset_y() const;

        void refresh() const;

        void move(int x, int y) const;

        void output(std::string s) const;

        void move_and_output(int x, int y, std::string s) const;

        void outputln(int y, std::string s) const;

        window subwindow(int _size_x, int _size_y, int offset_x, int offset_y);
};
} // namespace console_io

#endif
