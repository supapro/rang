#include "rwindow.hpp"

window::window(console_io::window &&_win, buffer &_tied_buf) : win(_win), tied_buf(_tied_buf)
{
}

void window::refresh()
{
        tied_buf.update();
        for (int y = 0; y < win.size_y && y < tied_buf.contents.size(); ++y) {
                std::string line = tied_buf.contents[y];
                line.resize(win.size_x, ' ');
                win.move_and_output(0, y, line);
        }
        win.refresh();
}
