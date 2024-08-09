#include <format>
#include <iostream>
#include <string>

#include "../include/binary_serialize.h"
#include "../include/user_entry.h"

namespace fs = std::filesystem;

int main() {
  UserEntry usr;
  if (is_empty(usr.path())) {
    try {
      std::string password;
      std::cout << "\t\tEnter the password:" << std::endl;
      std::cin >> password;
      usr.setpass(password);

      UserEntry::registration(usr);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  }

  try {
    std::cout << "\t\tUser is:" << std::endl;
    const std::vector data = binary_serialize::deserialize(usr.fs());
    std::cout << std::format("username:{}\npassword:{}\n", data[0], data[1]);
  } catch (const std::exception& e) {
    std::cerr << "Error:\t" << e.what() << std::endl;
  }

  return 0;
}
