#include "scroll.h"

void scroll(string &&s) {
  for(auto &c : s)
    std::cout << c << std::flush;
  std::cout << std::endl;
}
