//
// Created by ruslan on 8/3/24.
//

#ifndef PASS_UTILS_H
#define PASS_UTILS_H

#include <string>

namespace pass_utils {
std::string generate_salt(size_t len);
std::string hash(const std::string& password, const std::string& key,
                 const std::string& salt);
std::string unhash(const std::string& hash, const std::string& key,
                   const std::string& salt);
std::string encode(const std::string& password, const std::string& key,
                 const std::string& salt);
std::string decode(const std::string& encoded, const std::string& key,
                   const std::string& salt);
}  // namespace pass_utils

#endif  // PASS_UTILS_H
