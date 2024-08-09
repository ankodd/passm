#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <filesystem>

namespace fs = std::filesystem;

namespace sys_utils {
inline std::string systemusr() {
  std::string name = getenv("USER");
  if (name.data() == nullptr) {
    name = getenv("LOGNAME");
  }

  return name;
}

inline void ensure_security(const fs::path& path) {
  fs::permissions(path, fs::perms::owner_read | fs::perms::owner_write,
                  fs::perm_options::replace);
}
}  // namespace sys_utils

#endif  // FILE_UTILS_H
