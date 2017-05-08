#include "p1_wagon.h"
#include "p1_hill.h"
#include "game_vars.h"

#include "scene.h"

#include <iostream>
#include <memory>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::unique_ptr;

using std::make_unique;

unique_ptr<scene> p1_wagon(scene_args args) {
  int n;

  game_vars::hands_bound = true;
  game_vars::feet_bound = false;
  game_vars::blinded = true;
  
  n = std::stoi(args.at(0));

  switch(n) {
  case 1:
    game_vars::feet_bound = true;  
    return make_unique<game_scene>("p1_hill", p1_hill);
  case 2:
    game_vars::blinded = false;
  case 3:
    return make_unique<game_scene>("p1_hill", p1_hill);
  default:
    cout << "Invalid option." << endl;
    return make_unique<game_scene>();
  }
}