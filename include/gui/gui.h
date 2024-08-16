#ifndef MENU_H
#define MENU_H

#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>

#include "core/user_entry.h"

class GUI {
 public:
  GUI() = default;
  static void help();
  static void about_usr();
  static void registration();

 private:
  static inline UserEntry user = UserEntry();
  static inline ftxui::Screen screen =
      ftxui::Screen::Create(ftxui::Dimension::Full(), ftxui::Dimension::Full());
};

#endif  // MENU_H
