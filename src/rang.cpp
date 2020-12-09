#include "rang.hpp"
#include "buffer.hpp"
#include "window.hpp"
#include <algorithm>
#include <dirent.h>
#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <vector>

int main(int argc, char *argv[])
{
        int width, height;
        int ch;

        initscr(); /* Start curses mode 		*/
        start_color();
        use_default_colors();
        cbreak();             /* Line buffering disabled, Pass on
                               * everty thing to me 		*/
        keypad(stdscr, TRUE); /* I need that nifty F1 	*/
        noecho();

        height = LINES;
        width  = COLS;
        refresh();
        window mywin(width - 2, height - 2, 1, 1);
        directory_listing lst(".");
        lst.update();
        int current = 0;
        for (std::string &line : lst.contents) {
                mywin.move_and_output(0, current++, line);
        }
        mywin.refresh();
        getch();
        endwin();
        return 0;
}
