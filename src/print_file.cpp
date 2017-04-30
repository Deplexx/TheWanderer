#include "print_file.h"

#include <iostream>
#include <fstream>

void print_file(std::string&& fname) {
  std::ifstream fs(fname);
  std::cout << fs.rdbuf();
}
