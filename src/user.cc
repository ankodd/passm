#include "../include/user.h"

#include <cstdlib>
#include <filesystem>
#include <format>
#include <fstream>
#include <string>

#include "../include/binary_serialize.h"
#include "../include/file_utils.h"

namespace fs = std::filesystem;

User::User(std::string& password)
    : username(systemusr()), password(std::move(password)) {
  auto open_mode = openmode();
  file.open(file_path, open_mode);

  if (!file.is_open()) {
    throw std::runtime_error(
        std::format("file:{}\tis not opened", file_path.string()));
  }
}

User::User() : username(systemusr()) {
  const fs::path path = std::format("/home/{}/.passm", systemusr());
  if (is_dir()) {
    fs::create_directory(path);
  }

  file.open(file_path, openmode() | std::ios::binary);
  file_utils::ensure_security(file_path);

  if (!file.is_open()) {
    throw std::runtime_error(
        std::format("file:{}\tis not opened", file_path.string()));
  }
}

User::~User() { file.close(); }

bool User::is_registered() {
  if (fs::exists(file_path)) {
    if (!fs::file_size(file_path)) {
      return false;
    }
    return true;
  }

  return false;
}

void User::registration(User& user) {
  if (!user.file.is_open()) {
    throw std::runtime_error("User file could not be opened");
  }

  binary_serialize::serialize(user.fs(), {user.username, user.password});
}
