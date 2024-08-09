#ifndef USER_H
#define USER_H

#include <cstdlib>
#include <filesystem>
#include <format>
#include <fstream>
#include <string>

#include "entry.h"
#include "sys_utils.h"

class User : public Entry {
 public:
  User();
  explicit User(std::string& password);
  ~User();
  static bool is_registered();
  inline void setpass(const std::string& passwd) { password = passwd; }
  static void registration(User& user);

  inline std::fstream& fs() { return file; }

 private:
  static auto openmode() {
    return is_registered() ? std::ios::in : std::ios::out;
  }

  static inline bool is_dir() {
    return std::filesystem::exists(
        std::format("/home/{}/.passm", sys_utils::systemusr()));
  }

  std::string password;
  std::string username;

  static inline std::filesystem::path file_path =
      std::format("/home/{}/.passm/user.bin", sys_utils::systemusr());

  std::fstream file;
};

#endif  // USER_H
