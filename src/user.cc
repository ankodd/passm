#include "../include/user.h"

#include <cstdlib>
#include <filesystem>
#include <format>
#include <fstream>
#include <string>

namespace fs = std::filesystem;

User::User() {
  username = systemusr();
  userfile.path = std::format("/home/{}/.passm/user.bin", username);
  userfile.file = std::fstream(userfile.path, std::ios::in | std::ios::out | std::ios::app);
}

User::~User() { userfile.file.close(); }

std::string User::systemusr() {
  std::string name = getenv("USER");
  if (name.c_str() == nullptr) {
    name = getenv("LOGNAME");
  }

  return name;
}

bool User::is_registered() const {
  if (exists(userfile.path)) {
    return true;
  }

  return false;
}

void User::registration(const User& user) {
  if (user.userfile.file.is_open()) {
    throw std::runtime_error("User file could not be opened");
  }
}
