#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>

enum class Category { Email, Bank, SocialMedia, Other };

inline std::string category_to_str(Category category) {
  switch (category) {
    case Category::Email:
      return "Email";
    case Category::Bank:
      return "Bank";
    case Category::SocialMedia:
      return "SocialMedia";
    case Category::Other:
      return "Other";
  }
}

#endif  // CATEGORY_H
