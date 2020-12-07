#include "buffer.hpp"
#include <algorithm>
#include <iostream>

DirectoryListing::DirectoryListing(fs::path _directory) : directory(_directory)
{
        it = fs::directory_iterator(directory);
};

void DirectoryListing::update()
{
        std::vector<fs::directory_entry> filtered;
        std::copy_if(fs::begin(it), fs::end(it), std::back_insert_iterator(filtered),
                     [](fs::directory_entry entry) -> bool {
                             return entry.path().filename().string().front() != '.';
                     });
        std::sort(filtered.begin(), filtered.end(),
                  [](fs::directory_entry entry1, fs::directory_entry entry2) -> bool {
                          if (entry1.is_directory() != entry2.is_directory()) {
                                  return entry1.is_directory();
                          }
                          return entry1.path().filename().string() <
                              entry2.path().filename().string();
                  });
        contents.resize(filtered.size());
        transform(filtered.begin(), filtered.end(), contents.begin(),
                  [](fs::directory_entry entry) -> std::string {
                          return entry.path().filename().string();
                  });
}
