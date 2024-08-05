#include "../include/serializer.h"

#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

void Serializer::serialize(std::fstream& to,
                           const std::vector<std::string>& data) {
  if (!to.is_open()) {
    throw std::runtime_error("file for serialize doesn't opened");
  }

  size_t size = data.size();
  to.write(reinterpret_cast<const char*>(&size), sizeof(data.size()));

  for (const auto& str : data) {
    size_t len = str.size();
    to.write(reinterpret_cast<const char*>(&len), sizeof(len));
    to.write(str.data(), static_cast<long>(len));
  }
}

std::vector<std::string> Serializer::deserialize(std::fstream& from) {
  if (!from.is_open()) {
    throw std::runtime_error("file for deserialize doesn't opened");
  }

  return {};
}
