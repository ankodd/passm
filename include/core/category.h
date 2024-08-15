#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>

namespace category {
enum class Category { Email, Bank, SocialMedia, Other };

inline std::string to_str(Category category) {
  switch (category) {
    case Category::Email:
      return "email";
    case Category::Bank:
      return "bank";
    case Category::SocialMedia:
      return "socialmedia";
    default:
      return "other";
  }
}
}  // namespace category

#endif  // CATEGORY_H
