#ifndef __BUFFER_HPP
#define __BUFFER_HPP

#include "rang.hpp"
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

class buffer
{
      public:
        std::vector<std::string> contents;

        buffer() = default;

        void update();
};

class dummy : buffer
{
};

class directory_listing : public buffer
{
      private:
        fs::directory_iterator it;

      public:
        fs::path directory;

        directory_listing(fs::path _directory);

        void update();
};
#endif
