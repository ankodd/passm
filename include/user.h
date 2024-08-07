#ifndef USER_H
#define USER_H

#include <cstdlib>
#include <filesystem>
#include <format>
#include <fstream>
#include <string>

class User {
 public:
  User();
  explicit User(std::string& password);
  ~User();
  static bool is_registered();
  void setpass(const std::string&);
  static void registration(User& user);

  static inline std::string systemusr() {
    std::string name = getenv("USER");
    if (name.data() == nullptr) {
      name = getenv("LOGNAME");
    }

    return name;
  }

  inline std::fstream& fs() { return file; }

  inline void reopen_file(std::ios::openmode opmode) {
    file.close();
    file.open(file_path, opmode | std::ios::binary);
  }

 private:
  static auto openmode() {
    return is_registered() ? std::ios::in : std::ios::out;
  }

  static inline bool is_dir() {
    return std::filesystem::exists(std::format("/home/{}/.passm", systemusr()));
  }

  std::string password;
  std::string username;

  static inline std::filesystem::path file_path =
      std::format("/home/{}/.passm/user.bin", systemusr());

  std::fstream file;
};

#endif  // USER_H
