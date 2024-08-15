#ifndef BINARY_SERIALIZE_H
#define BINARY_SERIALIZE_H

#include <exception>
#include <string>
#include <vector>

namespace binary_serialize {
class bad_serialize final : public std::exception {
 public:
  explicit bad_serialize(const char* msg) : msg(msg) {}
  [[nodiscard]] const char* what() const noexcept override {
    return msg.c_str();
  }

 private:
  std::string msg;
};

void serialize(std::fstream& fs, const std::vector<std::string>& data);
std::vector<std::string> deserialize(std::fstream& fs);
};  // namespace binary_serialize

#endif  // BINARY_SERIALIZE_H
