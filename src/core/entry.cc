#include "core/entry.h"

#include <filesystem>
#include <format>

#include "utils/sys_utils.h"

Entry::Entry(const std::filesystem::path& fpath) : fpath(fpath) {
  if (!exists(rootpath)) {
    create_directory(rootpath);
  }

  if (exists(fpath) && !is_empty(fpath)) {
    opmode = std::ios::in;
  }

  file.open(fpath, opmode | std::ios::binary);
  if (!file.is_open()) {
    throw std::runtime_error(
        std::format("file:{}\t doesn't opened", fpath.string()));
  }

  sys_utils::ensure_security(fpath);
}
