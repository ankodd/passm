#include <cstdlib>
#include <filesystem>
#include <format>
#include <fstream>
#include <iostream>
#include <string>
#include "../include/user.h"


int main(int argc, char** argv) {
  const User user;
  if (user.is_registered()) {
    std::cout << "You are registered!\n";
  } else {
    std::cout << "You are not registered!\n";
  }

  return 0;
}

// const std::string user = username();
// const std::string path = std::format("/home/{}/.passm", user);
// std::cout << path;
//
// if (std::filesystem::is_directory("/home/ruslan/.passm")) {
//   std::filesystem::create_directory("/home/ruslan/.passm");
// }
