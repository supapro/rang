#ifndef __EVLOOP_HPP
#define __EVLOOP_HPP

#include <boost/asio.hpp>
#include <functional>
#include <string>
#include <vector>

#undef timeout

namespace rang
{
class event_loop
{
      private:
        boost::asio::io_context io_context;
        boost::asio::signal_set signals;
        boost::asio::posix::stream_descriptor input;

      public:
        event_loop();

        template <class duration>
        void add_regular_job(const std::function<void()> callback,
                             const duration &interval); // TODO implementation

        template <class time_point>
        void add_job(const std::function<void()> callback, time_point &time); // TODO implementation

        void set_input_reaction(const std::function<void(int)> callback);

        void run();

        void stop();

      private:
        void handle_input(const std::function<void(int)> &callback);
};
} // namespace rang
#endif
