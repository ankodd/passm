#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <fstream>
#include <string>
#include <vector>

class Serializer {
 public:
  Serializer() = default;
  static void serialize(std::fstream& to, const std::vector<std::string>& data);
  static std::vector<std::string> deserialize(std::fstream& from);

 private:
};

#endif  // SERIALIZER_H
