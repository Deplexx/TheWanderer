#include <fstream>
#include <iostream>

#include <memory>
#include <vector>

#include <stdint.h>

#include "TheWanderer.hpp"

static TheWanderer tw = TheWanderer();

int main(int argc, char *argv[]) {
  tw.run();
  
  return 0;
}

