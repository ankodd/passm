#ifndef BINARY_SERIALIZE_H
#define BINARY_SERIALIZE_H

#include <string>
#include <vector>
#include <exception>

namespace binary_serialize {
class bad_serialize final : public std::exception {
public:
  explicit bad_serialize(const std::string& msg) : msg(msg) {}
  const char* what() const noexcept override {
    return (std::string("serialize error:\t") + msg).c_str();
  }

private:
  std::string msg;
};

void serialize(std::fstream& fs, const std::vector<std::string>& data);
std::vector<std::string> deserialize(std::fstream& fs);
};  // namespace binary_serialize

#endif  // BINARY_SERIALIZE_H
