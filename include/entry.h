#ifndef ENTRY_H
#define ENTRY_H

#include <filesystem>
#include <format>
#include <fstream>

#include "sys_utils.h"

class Entry {
 public:
  explicit Entry(const std::filesystem::path& fpath);
  ~Entry() { file.close(); }

  void reopen() {
    file.close();
    change_opmode();
    file.open(fpath, opmode | std::ios::binary);
  }

  std::fstream& fs() { return file; } // ref to file stream
  const std::fstream& fs() const { return file; }
  std::filesystem::path& path() { return fpath; }
  const std::filesystem::path& path() const { return fpath; }

 protected:
  std::ios::openmode opmode = std::ios::out;
  std::fstream file;
  std::filesystem::path fpath;
  const static inline std::filesystem::path rootpath =
      std::format("/home/{}/.passm", sys_utils::systemusr());

private:
  void change_opmode() {
    opmode = ((opmode == std::ios::out) ? std::ios::in : std::ios::out);
  }
};

#endif  // ENTRY_H
