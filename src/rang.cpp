#include "rang.h"
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
        std::vector<fs::directory_entry> filtered;
        auto it = fs::directory_iterator(".");
        std::copy_if(fs::begin(it), fs::end(it), std::back_insert_iterator(filtered),
                     [](fs::directory_entry entry) -> bool {
                             return entry.path().filename().string().front() != '.';
                     });
        std::sort(filtered.begin(), filtered.end(),
                  [](fs::directory_entry entry1, fs::directory_entry entry2) -> bool {
                          if (entry1.is_directory() != entry2.is_directory()) {
                                  return entry1.is_directory();
                          }
                          return entry1.path().filename().string() < entry2.path().filename().string();
                  });
        for (auto entry : filtered) {
                wprintw(my_win, "%s\n", entry.path().filename().c_str());
        }
        wrefresh(my_win);
        getch();

        endwin(); /* End curses mode		  */
        return 0;
}
