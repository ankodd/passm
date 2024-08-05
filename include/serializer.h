#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <fstream>
#include <string>
#include <vector>

namespace  serializer {
inline void serialize(std::fstream& fs, const std::vector<std::string>& data) {
  if (!fs.is_open()) {
    throw std::runtime_error("file for serialize doesn't opened");
  }

  const auto obj_len = data.size();
  fs.write(reinterpret_cast<const char*>(&obj_len), sizeof(obj_len));

  for (const auto& str : data) {
    const auto len = str.length();
    fs.write(reinterpret_cast<const char*>(&len), sizeof(len));
    fs.write(str.data(), len);
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
    fs.read(t.data(), len);
    data.push_back(std::move(t));
  }

  return data;
}

}; //  namespace Serializer

#endif  // SERIALIZER_H
