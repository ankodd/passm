#include "core/user_entry.h"

#include "utils/sys_utils.h"

UserEntry::UserEntry() : Entry(fpath), username(sys_utils::systemusr()) {}

UserEntry::UserEntry(const std::string& password) : UserEntry() {
  setpass(password);
}

bool UserEntry::is_registered() {
  if (!is_empty(fpath)) {
    return true;
  }

  return false;
}
