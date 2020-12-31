#include "buffer.hpp"
#include "console_io.hpp"
#include "evloop.hpp"
#include "rwindow.hpp"
#include <algorithm>
#include <iostream>
#include <ncurses.h>

int main(int argc, char *argv[])
{
        console_io::ncurses root;
        cbreak();              /* Line buffering disabled, Pass on
                                *everty thing to me */
        root.set_keypad(true); /* I need that nifty F1 	*/
        keypad(stdscr, TRUE);
        noecho();
        curs_set(0);
        root.refresh();
        console_io::window mywin =
            root.subwindow(root.get_size_x() - 2, root.get_size_y() - 2, 1, 1);
        rang::directory_listing lst(".");
        lst.update();
        rang::window main(std::move(mywin), lst);
        root.refresh();
        int ch;
        main.refresh();
        rang::event_loop loop;
        std::function<void(int)> reaction_func = [&](int ch) {
                if (ch == KEY_F(1)) {
                        loop.stop();
                        return;
                }
                try {
                        switch (ch) {
                        case KEY_DOWN:
                        case 'j':
                                main.scroll_viewport(1);
                                break;
                        case KEY_UP:
                        case 'k':
                                main.scroll_viewport(-1);
                                break;
                        default:
                                return;
                        }
                        main.refresh();
                } catch (error_t) {
                }
        };
        loop.set_input_reaction(reaction_func);
        loop.run();
        return 0;
}
