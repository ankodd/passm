#include <cstdlib>
#include <format>
#include <iostream>
#include <string>

#include "../include/binary_serialize.h"
#include "../include/user.h"

namespace fs = std::filesystem;

int main(int argc, char** argv) {
  User usr;
  if (!User::is_registered()) {
    try {
      std::string password;
      std::cout << "\t\tEnter the password:" << std::endl;
      std::cin >> password;
      usr.setpass(password);

      User::registration(usr);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  }

  try {
    usr.reopen_file(std::ios::in);
    std::cout << "\t\tUser is:" << std::endl;
    const auto data = binary_serialize::deserialize(usr.fs());
    std::cout << std::format("username:{}\npassword:{}\n", data[0], data[1]);
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
