#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <filesystem>

namespace fs = std::filesystem;

namespace file_utils {
inline void ensure_security(const fs::path& path) {
  fs::permissions(path, fs::perms::owner_read | fs::perms::owner_write,
                  fs::perm_options::replace);
}
}  // namespace file_utils

#endif  // FILE_UTILS_H
