#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <filesystem>
#include <format>

namespace fs = std::filesystem;

namespace sys_utils {
inline std::string systemusr() {
  std::string name = getenv("USER");
  if (name.data() == nullptr) {
    name = getenv("LOGNAME");
  }

  return name;
}

inline void ensure_security(const fs::path& fpath) {
  permissions(fpath, fs::perms::owner_read | fs::perms::owner_write,
              fs::perm_options::replace);
}

inline std::string rootpath() {
  return std::format("/home/{}/.passm", systemusr());
}
}  // namespace sys_utils

#endif  // FILE_UTILS_H
