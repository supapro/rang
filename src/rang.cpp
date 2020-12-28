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
        cbreak();             /* Line buffering disabled, Pass on
                               * everty thing to me 		*/
        keypad(stdscr, TRUE); /* I need that nifty F1 	*/
        noecho();
        curs_set(0);
        root.refresh();
        console_io::window mywin =
            root.subwindow(root.get_size_x() - 2, root.get_size_y() - 2, 1, 1);
        directory_listing lst(".");
        lst.update();
        window main(std::move(mywin), lst);
        root.refresh();
        int ch;
        main.refresh();
        while ((ch = getch()) != KEY_F(1)) {
                try {
                        switch (ch) {
                        case 'j':
                        case KEY_DOWN:
                                main.scroll_viewport(1);
                                break;
                        case 'k':
                        case KEY_UP:
                                main.scroll_viewport(-1);
                                break;
                        }
                        root.outputln(root.get_size_y() - 1, "OK");
                } catch (int) {
                        root.outputln(root.get_size_y() - 1, "Error found");
                }
                root.refresh();
                main.refresh();
        }
        return 0;
}
