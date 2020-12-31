#ifndef __BUFFER_HPP
#define __BUFFER_HPP

#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

namespace rang
{
class buffer
{
      public:
        std::vector<std::string> contents;

        buffer() = default;

        virtual ~buffer() = default;

        virtual void update() = 0;
};

class dummy : buffer
{
};

class directory_listing : public buffer
{
      public:
        fs::path directory;

        directory_listing(fs::path _directory);

        void update();
};
} // namespace rang
#endif
