//
// Created by ruslan on 8/3/24.
//

#ifndef MENU_H
#define MENU_H

#include "user.h"

class Menu {
 public:
  Menu();
  static void help();

 private:
  User user;
};

#endif  // MENU_H
