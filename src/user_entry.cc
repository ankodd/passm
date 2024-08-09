#include "../include/user_entry.h"

#include <filesystem>
#include <fstream>

#include "../include/binary_serialize.h"
#include "../include/sys_utils.h"

UserEntry::UserEntry()
: Entry(fpath), username(sys_utils::systemusr()) {}

UserEntry::UserEntry(const std::string& password)
  : UserEntry() {
  setpass(password);
}

bool UserEntry::is_registered() {
  if (!is_empty(fpath)) {
    return true;
  }

  return false;
}

void UserEntry::registration(UserEntry& user) {
  if (!user.file.is_open()) {
    throw std::runtime_error("User file could not be opened");
  }

  binary_serialize::serialize(user.fs(), {user.username, user.password});
  user.reopen();
}
