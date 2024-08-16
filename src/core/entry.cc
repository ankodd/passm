#include "core/entry.h"

#include <filesystem>

#include "utils/sys_utils.h"

Entry::Entry(const std::filesystem::path& fpath) : fpath(fpath) {
  if (!exists(rootpath)) {
    create_directory(rootpath);
  }

  if (exists(fpath) && !is_empty(fpath)) {
    opmode = std::ios::in;
  }
  sys_utils::ensure_security(fpath);
}
