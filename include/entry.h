#ifndef ENTRY
#define ENTRY

#include <filesystem>
#include <format>
#include <fstream>

#include "sys_utils.h"

class Entry {
 public:
  Entry();
  ~Entry() { file.close(); }

  inline void reopen_file(std::ios::openmode opmode) {
    file.close();
    file.open(path, opmode | std::ios::binary);
  }

 protected:
  std::fstream file;
  std::filesystem::path path;
  static inline std::filesystem::path rootpath =
      std::format("/home/{}/.passm", sys_utils::systemusr());
};

#endif  // ENTRY
