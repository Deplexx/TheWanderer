#ifndef _GAMEVARS_H_
#define _GAMEVARS_H_

#include <iostream>
#include <vector>

using namespace std;

struct GameVars {
  static bool hands_bound;
  static bool feet_bound;
  static bool blinded;
  static vector<string> items;
};
#endif
