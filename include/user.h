#ifndef USER_H
#define USER_H

#include <filesystem>
#include <format>
#include <fstream>
#include <string>
#include <memory>

class User {
 public:
  User() = default;
  explicit User(const std::string& password);
  ~User();
  static bool is_registered();
  static void registration(User& user);
  static std::string systemusr();
  inline std::fstream& fs() {
    return file;
  }

 private:
  std::string password;
  std::string username;
  std::filesystem::path file_path;
  std::fstream file;
};

#endif  // USER_H
