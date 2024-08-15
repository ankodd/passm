#include "gui/menu.h"

#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/dom/table.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>

#include "core/user_entry.h"

Menu::Menu() : user(UserEntry()) {}

void Menu::about_usr() {
  using namespace ftxui;
  std::string username = UserEntry::name();
  std::string path = user.path();
  std::string is_registered = UserEntry::is_registered() ? "true" : "false";

  auto table = Table(
      {{"Name", "Path", "Is registered"}, {username, path, is_registered}});
  table.SelectAll().Border(LIGHT);
  table.SelectRow(0).Decorate(bold);
  table.SelectRow(0).Border(DOUBLE);

  auto doc = table.Render();
  doc |= center;
  doc |= border;
  auto screen = Screen::Create(Dimension::Full(), Dimension::Full());
  Render(screen, doc);

  screen.Print();
}

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
