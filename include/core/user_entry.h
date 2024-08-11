#ifndef USER_H
#define USER_H

#include <filesystem>
#include <format>
#include <string>

#include "entry.h"
#include "utils/sys_utils.h"
#include "binary_serialize.h"

class UserEntry final : public Entry {
 public:
  UserEntry();
  explicit UserEntry(const std::string& password);
  static bool is_registered();

  void save() override {
    if (!file.is_open()) {
      throw std::runtime_error("User file could not be opened");
    }

    binary_serialize::serialize(fs(), {username, password});
    reopen();
  }

 private:
  std::string username;
  static inline std::filesystem::path fpath =
      std::format("/home/{}/.passm/user.bin", sys_utils::systemusr());
};

#endif  // USER_H
