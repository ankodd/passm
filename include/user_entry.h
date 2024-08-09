#ifndef USER_H
#define USER_H

#include <filesystem>
#include <format>
#include <string>

#include "entry.h"
#include "sys_utils.h"

class UserEntry : public Entry {
 public:
  UserEntry();
  explicit UserEntry(const std::string& password);
  static bool is_registered();
  void setpass(const std::string& passwd) { password = passwd; }
  static void registration(UserEntry& user);

 private:
  std::string password;
  std::string username;
  static inline std::filesystem::path fpath =
      std::format("/home/{}/.passm/user.bin", sys_utils::systemusr());
};

#endif  // USER_H
