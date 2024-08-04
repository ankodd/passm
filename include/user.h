#ifndef USER_H
#define USER_H

#include <filesystem>
#include <fstream>
#include <string>

class User {
 public:
  User();
  ~User();
  bool is_registered() const;
  static void registration(const User& user);

 private:
  static std::string systemusr();
  std::string password;
  std::string username;
  struct {
    std::filesystem::path path;
    std::fstream file;
  } userfile;
};

#endif USER_H
