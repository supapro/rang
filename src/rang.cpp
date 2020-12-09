#include "buffer.hpp"
#include "console_io.hpp"
#include <algorithm>
#include <iostream>
#include <ncurses.h>

int main(int argc, char *argv[])
{
        int width;
        int height;

        console_io::ncurses root;
        start_color();
        use_default_colors();
        cbreak();             /* Line buffering disabled, Pass on
                               * everty thing to me 		*/
        keypad(stdscr, TRUE); /* I need that nifty F1 	*/
        noecho();

        height = LINES;
        width  = COLS;
        root.refresh();
        console_io::window mywin = root.subwindow(width - 2, height - 2, 1, 1);
        directory_listing lst(".");
        lst.update();
        int current = 0;
        for (std::string &line : lst.contents) {
                mywin.move_and_output(0, current++, line);
        }
        mywin.refresh();
        getch();
        return 0;
}
