#include "rang.hpp"
#include "buffer.hpp"
#include <algorithm>
#include <dirent.h>
#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <vector>

int main(int argc, char *argv[])
{
        WINDOW *my_win;
        int width, height;
        int ch;

        initscr();            /* Start curses mode 		*/
        cbreak();             /* Line buffering disabled, Pass on
                               * everty thing to me 		*/
        keypad(stdscr, TRUE); /* I need that nifty F1 	*/
        noecho();

        height = LINES;
        width  = COLS;
        refresh();
        WINDOW *box_win = newwin(height, width, 0, 0);
        box(box_win, 0, 0);
        my_win = newwin(height - 2, width - 2, 1, 1);
        wrefresh(box_win);
        wrefresh(my_win);
        DirectoryListing lst(".");
        lst.update();
        for (std::string &dirname : lst.contents) {
                wprintw(my_win, "%s\n", dirname.c_str());
        }
        wrefresh(my_win);
        getch();

        endwin(); /* End curses mode		  */
        return 0;
}
