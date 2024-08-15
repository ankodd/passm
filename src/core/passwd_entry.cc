#include "core/passwd_entry.h"

PasswdEntry::PasswdEntry(const std::string& desc,
                         const category::Category& category)
    : Entry(create_path(desc, category)),
      description(desc),
      category(category) {}
