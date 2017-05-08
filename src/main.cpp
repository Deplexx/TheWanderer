// #include "game.h"

// int main(int argc, char *argv[]) {
//   game_run();

//   return 0;
// }

#include <string>

struct A {
  A(std::string s) {}
};

struct B : A {
  B(std::string s) : A(s) {}
};

int main(int argc, char *argv[]) {
  B b("derived");

  return 0;
}
