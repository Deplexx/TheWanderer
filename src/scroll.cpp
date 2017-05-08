#include "scroll.h"

#include <chrono>
#include <thread>

#include <iostream>

using std::cout;
using std::endl;
using std::flush;

using namespace std::chrono_literals;

void scroll(string &&s) {
  for(auto &c : s) {
    std::cout << c << std::flush; std::this_thread::sleep_for(50ms);
  }
  std::cout << std::endl;
}
