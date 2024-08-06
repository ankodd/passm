#include "../include/user.h"

#include <cstdlib>
#include <filesystem>
#include <format>
#include <fstream>
#include <string>

#include "../include/binary_serialize.h"

namespace fs = std::filesystem;

User::User(const std::string& password) : username(systemusr()), password(std::move(password)),
  file_path(std::format("/home/{}/.passm/user.bin", username)) {
  auto open_mode = is_registered() ? std::ios::in : std::ios::out;
  file.open("/home/ruslan/.passm/user.bin", open_mode);

  if (!file.is_open()) {
    throw std::runtime_error(std::format("file:{}\tis not opened", file_path.string()));
  }
}

User::~User() { file.close(); }

std::string User::systemusr() {
  std::string name = getenv("USER");
  if (name.data() == nullptr) {
    name = getenv("LOGNAME");
  }

  return name;
}

bool User::is_registered() {
  return fs::exists(std::format("/home/{}/.passm/user.bin", systemusr()));
}

void User::registration(User& user) {
  if (!user.file.is_open()) {
    throw std::runtime_error("User file could not be opened");
  }

  std::vector data = {
    user.username, user.password
  };

  binary_serialize::serialize(user.file, data);
}
