#include "read_line.h"

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char *argv[]) {
  vector<string>  args = read_line();

  cout << args[0];

  return 0;
}