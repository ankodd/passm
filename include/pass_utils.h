//
// Created by ruslan on 8/3/24.
//

#ifndef PASS_UTILS_H
#define PASS_UTILS_H

#include <string>

namespace pass_utils {
std::string generate_salt(size_t len);
std::string hash(const std::string& password, const std::string& key, const std::string& salt);
}


#endif //PASS_UTILS_H
