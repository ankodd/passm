#include "gui/menu.h"

#include <iostream>

void Menu::help() {
  std::cout << "passm\tversion 0.1\n";
  std::cout << "All commands executing only with sudo\n";
  std::cout << "Usage: passm <title>\t Display password to stdout\n";

  std::cout << "Optional settings:\n";
  std::cout << "-n <title> <password>\t Create new entry\n";
  std::cout << "-l\t\t\t Display list of passwords\n";
  std::cout << "-d <title> <password>\t Delete password\n";
  std::cout << "-g <title>\t\t Generate password and copy to clipboard\n";
  std::cout << "-c <title>\t\t Copy password to clipboard\n";
  std::cout << "--version\t\t display version\n";
}
