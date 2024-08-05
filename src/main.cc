#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdint>

#include "../include/serializer.h"

int main(int argc, char** argv) {
  std::fstream file;
  file.open("../tests/testfile.bin", std::ios::in | std::ios::binary);
  std::vector<std::string> des_data = serializer::deserialize(file);

  for (const auto& str: des_data) {
    std::cout << str << std::endl;
  }

  return 0;
}
