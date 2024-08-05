#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "../include/serializer.h"

int main(int argc, char** argv) {
  std::vector<std::string> data = {"ruslan", "qwerty123"};
  std::fstream file;
  file.open("../tests/testfile.bin", std::ios::binary | std::ios::out);
  Serializer::serialize(file, data);

  file.close();
  return 0;
}
