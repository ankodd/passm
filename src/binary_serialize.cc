#include <fstream>
#include <vector>
#include <string>
#include <cstdint>

#include "../include/binary_serialize.h"

void binary_serialize::serialize(std::fstream& fs, const std::vector<std::string>& data) {
  if (data.empty()) {
    throw bad_serialize("Empty data");
  }

  if (!fs.is_open()) {
    throw std::runtime_error("file for serialize doesn't opened");
  }

  const auto obj_len = data.size();
  fs.write(reinterpret_cast<const char*>(&obj_len), sizeof(obj_len));

  for (const auto& str : data) {
    size_t len = str.size();
    fs.write(reinterpret_cast<const char*>(&len), sizeof(len));
    fs.write(str.data(), static_cast<uint32_t>(len));
  }
}

std::vector<std::string> binary_serialize::deserialize(std::fstream& fs) {
  if (!fs.is_open()) {
    throw std::runtime_error("file for deserialize doesn't opened");
  }

  std::vector<std::string> data;
  size_t obj_len = 0;
  fs.read(reinterpret_cast<char*>(&obj_len), sizeof(obj_len));

  if (!obj_len) {
    throw bad_serialize("Empty data for deserialize");
  }

  for (int i = 0; i < obj_len; ++i) {
    size_t len = 0;
    fs.read(reinterpret_cast<char*>(&len), sizeof(len));

    std::string t(len, '\0');
    fs.read(t.data(), static_cast<uint32_t>(len));
    data.push_back(std::move(t));
  }

  return data;
}