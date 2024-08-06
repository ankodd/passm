#include <cstdint>
#include <cstdlib>
#include <filesystem>
#include <format>
#include <fstream>
#include <iostream>
#include <string>

#include "../include/binary_serialize.h"
#include "../include/user.h"

namespace fs = std::filesystem;

int main(int argc, char** argv) {
  std::string password;
  std::cout << "\t\tEnter the password:" << std::endl;
  std::cin >> password;

  User usr(password);
  if (!User::is_registered()) {
    try {
      fs::path path = std::format("/home/{}/.passm", User::systemusr());
      fs::create_directory(path);

      User::registration(usr);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  }

  try {
    std::cout << "\t\tUser is:" << std::endl;
    const auto data = binary_serialize::deserialize(usr.fs());
    std::cout << std::format("username:{}\npassword:{}\n", data[0], data[1]);
  } catch(std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
