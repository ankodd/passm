#ifndef ENTRY_H
#define ENTRY_H

#include <filesystem>
#include <fstream>

#include "utils/sys_utils.h"

class Entry {
 public:
  explicit Entry(const std::filesystem::path& fpath);
  virtual ~Entry() noexcept { file.close(); }

  void reopen() {
    file.close();
    change_opmode();
    file.open(fpath, opmode | std::ios::binary);
  }

  virtual void save() = 0;

  std::fstream& fs() { return file; }
  const std::fstream& fs() const { return file; }

  const std::filesystem::path& path() { return fpath; }
  const std::filesystem::path& path() const { return fpath; }

  void setpass(const std::string& value) { password = value; }
  const std::string& pass() const { return password; }

  void fopen() {
    file.open(fpath, opmode | std::ios::binary);
    if (!file.is_open()) {
      throw std::runtime_error(
          std::format("file:{}\t doesn't opened", fpath.string()));
    }
  }

 protected:
  std::ios::openmode opmode = std::ios::out;
  std::fstream file;
  std::string password;
  const std::filesystem::path fpath;
  const static inline std::filesystem::path rootpath = sys_utils::rootpath();

 private:
  void change_opmode() {
    opmode = ((opmode == std::ios::out) ? std::ios::in : std::ios::out);
  }
};

#endif  // ENTRY_H
