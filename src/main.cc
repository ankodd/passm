#include <format>
#include <iostream>
#include <string>

#include "../include/binary_serialize.h"
#include "../include/user_entry.h"
#include "../include/initialize.h"
#include "../include/passwd_entry.h"

namespace fs = std::filesystem;

namespace test {
void first() {
  UserEntry usr;
  if (is_empty(usr.path())) {
    try {
      std::string password;
      std::cout << "\t\tEnter the password:" << std::endl;
      std::cin >> password;
      usr.setpass(password);

      usr.save();
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
}

void second() {
  std::string desc;
  std::string password;
  category::Category category;
  char choice;

  std::cout << "Enter description: ";
  std::getline(std::cin, desc);

  std::cout << "Choice category:\n1\tSocialMedia\n2\tBank\n2\tEmail\n3\tOther\n";
  std::cin >> choice;

  switch (choice) {
    using enum category::Category;
    case '1':
      category = SocialMedia;
      break;
    case '2':
      category = Bank;
      break;
    case '3':
      category = Email;
      break;
    case '4':
      category = Other;
      break;
    default:
      throw std::runtime_error("invalid choice");
  }

  PasswdEntry passwd_entry(desc, category);

  if (is_empty(passwd_entry.path())) {
    std::string pass;
    std::cout << "Enter password: ";
    std::cin >> password;
    passwd_entry.setpass(password);

    passwd_entry.save();
  } else {
    std::cout << passwd_entry.desc() << ":\n";
    try {
      std::vector data = binary_serialize::deserialize(passwd_entry.fs());
      std::cout << std::format("description: {}\npassword: {}", data[0], data[1]);
    } catch (std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  }
}
}

int main() {
  if (!initialize::is_init()) {
    initialize::init();
  }

  test::second();

  return 0;
}
