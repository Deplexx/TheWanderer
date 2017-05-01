#ifndef _GAMEVARS_H_
#define _GAMEVARS_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

struct game_vars {
  static bool intro_complete;

  static bool hands_bound;
  static bool feet_bound;
  static bool blinded;

  static vector<string> items;
};

#endif
