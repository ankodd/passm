#ifndef MENU_H
#define MENU_H

#include "core/user_entry.h"

class Menu {
 public:
  explicit Menu();
  static void help();
  void about_usr();

 private:
  UserEntry user;
};

#endif  // MENU_H
