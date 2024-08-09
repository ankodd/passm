//
// Created by ruslan on 8/3/24.
//

#ifndef MENU_H
#define MENU_H

#include "user_entry.h"

class Menu {
 public:
  Menu() = default;
  static void help();

 private:
  UserEntry user;
};

#endif  // MENU_H
