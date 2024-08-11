#ifndef PASSWD_ENTRY_H
#define PASSWD_ENTRY_H

#include "binary_serialize.h"
#include "entry.h"
#include "category.h"

class PasswdEntry final : public Entry {
public:
  PasswdEntry(const std::string& desc, const category::Category& category);
  void save() override {
    if (!file.is_open()) {
      throw std::runtime_error("User file could not be opened");
    }

    binary_serialize::serialize(fs(), {description, password});
    reopen();
  }

  const std::string& desc() { return description; }

private:
  static std::filesystem::path create_path(const std::string& desc,
                                           const category::Category& category) {
    return std::format("{}/{}/{}.bin", sys_utils::rootpath(), to_str(category), desc);
  }

  std::string description;
  category::Category category;
};

#endif // PASSWD_ENTRY_H