#ifndef INITIALIZE_H
#define INITIALIZE_H

#include <filesystem>
#include <format>

#include "sys_utils.h"

namespace initialize {
inline bool is_init() { return std::filesystem::exists(sys_utils::rootpath()); }

inline void init() {
  std::filesystem::create_directory(sys_utils::rootpath());
  std::filesystem::create_directory(
      std::format("{}/socialmedia", sys_utils::rootpath()));
  std::filesystem::create_directory(
      std::format("{}/bank", sys_utils::rootpath()));
  std::filesystem::create_directory(
      std::format("{}/email", sys_utils::rootpath()));
  std::filesystem::create_directory(
      std::format("{}/other", sys_utils::rootpath()));
}
}  // namespace initialize

#endif  // INITIALIZE_H
