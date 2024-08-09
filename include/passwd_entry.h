#ifndef PASSWD_ENTRY_H
#define PASSWD_ENTRY_H

#include "entry.h"
#include "category.h"

class PasswdEntry : public Entry {
public:
private:
  std::string password;
  std::string description;
  Category category;
};

#endif // PASSWD_ENTRY_H