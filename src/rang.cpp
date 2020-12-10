#include "buffer.hpp"
#include "console_io.hpp"
#include "rwindow.hpp"
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
        curs_set(0);

        height = LINES;
        width  = COLS;
        root.refresh();
        console_io::window mywin = root.subwindow(width - 2, height - 2, 1, 1);
        directory_listing lst(".");
        window main(std::move(mywin), lst);
        main.refresh();
        getch();
        return 0;
}
