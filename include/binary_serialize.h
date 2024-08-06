#ifndef BINARY_SERIALIZE_H
#define BINARY_SERIALIZE_H

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

namespace binary_serialize {
inline void serialize(std::fstream& fs, const std::vector<std::string>& data) {
  if (!fs.is_open()) {
    throw std::runtime_error("file for serialize doesn't opened");
  }

  const auto obj_len = data.size();
  fs.write(reinterpret_cast<const char*>(&obj_len), sizeof(obj_len));

  for (const auto& str : data) {
    size_t len = str.size();
    fs.write(reinterpret_cast<const char*>(&len), sizeof(len));
    fs.write(str.data(), static_cast<int>(len));
  }
}

inline std::vector<std::string> deserialize(std::fstream& fs) {
  if (!fs.is_open()) {
    throw std::runtime_error("file for serialize doesn't opened");
  }

  std::vector<std::string> data;
  size_t obj_len = 0;
  fs.read(reinterpret_cast<char*>(&obj_len), sizeof(obj_len));

  for (int i = 0; i < obj_len; ++i) {
    size_t len = 0;
    fs.read(reinterpret_cast<char*>(&len), sizeof(len));

    std::string t(len, '\0');
    fs.read(t.data(), static_cast<uint32_t>(len));
    data.push_back(std::move(t));
  }

  return data;
}

};  // namespace binary_serialize

#endif  // SERIALIZER_H


#endif // BINARY_SERIALIZE_H
