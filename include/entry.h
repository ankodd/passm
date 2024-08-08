#ifndef ENTRY
#define ENTRY

#include <filesystem>
#include <format>
#include <fstream>

class Entry {
 public:
  Entry();
  ~Entry() { file.close(); }
  static inline std::string systemusr() {
    std::string name = getenv("USER");
    if (name.data() == nullptr) {
      name = getenv("LOGNAME");
    }

    return name;
  }

  inline void reopen_file(std::ios::openmode opmode) {
    file.close();
    file.open(path, opmode | std::ios::binary);
  }

 private:
  std::fstream file;
  std::filesystem::path path;
  static inline std::filesystem::path rootpath =
      std::format("/home/{}/.passm", systemusr());
};

#endif  // ENTRY
