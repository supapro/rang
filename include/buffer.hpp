#ifndef __BUFFER_HPP
#define __BUFFER_HPP

#include "rang.hpp"
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

class Buffer
{
      public:
        std::vector<std::string> contents;

        Buffer() = default;

        void update();
};

class Dummy : Buffer
{
};

class DirectoryListing : public Buffer
{
      private:
        fs::directory_iterator it;

      public:
        fs::path directory;

        DirectoryListing(fs::path _directory);

        void update();
};
#endif
