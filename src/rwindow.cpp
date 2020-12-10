#include "rwindow.hpp"

window::window(console_io::window &&_win, buffer &_tied_buf) : win(_win), tied_buf(_tied_buf)
{
}

void window::refresh()
{
        for (int y = 0; y < win.size_y; ++y) {
                if (offset_y + y < tied_buf.contents.size()) {
                        win.outputln(y, tied_buf.contents[offset_y + y]);
                } else {
                        win.outputln(y, "");
                }
        }
        win.refresh();
}

void window::scroll_viewport(int shift)
{
        if (offset_y + shift >= tied_buf.contents.size() || offset_y + shift < 0) {
                throw 1; // todo errors
        }
        offset_y += shift;
}
