#include "evloop.hpp"
#include <iostream>
#include <ncurses.h>

#undef timeout

using namespace rang;

event_loop::event_loop()
    : signals(io_context, SIGINT, SIGTERM), // handle SIGINT and SIGTERM signals
      input(io_context, STDIN_FILENO)       // take input from stdin stream
{
        signals.async_wait([&](auto, auto) { io_context.stop(); });
}

void event_loop::run()
{
        io_context.run();
}

void event_loop::stop()
{
        io_context.stop();
}

void event_loop::set_input_reaction(const std::function<void(int)> callback)
{
        input.cancel();
        handle_input(callback);
}

void event_loop::handle_input(const std::function<void(int)> &callback)
{
        input.async_wait(boost::asio::posix::stream_descriptor::wait_read,
                         [this, callback](auto error) {
                                 if (!error) {
                                         callback(getch());
                                 }
                                 handle_input(callback);
                         });
}
