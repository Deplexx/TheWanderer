#include "p1_wagon.h"
#include "p1_hill.h"
#include "game_vars.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

static scene kick();
static scene jump();
static scene wait();

scene p1_wagon(scene_args args) {
  int n;

  game_vars::hands_bound = true;
  game_vars::feet_bound = false;
  game_vars::blinded = true;
  
  switch(std::stoi(args[0], &n)) {
  case 1:
    return kick();
  case 2:
    return jump();
  case 3:
    return wait();
  default:
    cout << "Invalid option." << endl;
  }
}

static scene kick() {
  game_vars::feet_bound = true;
  print_file("p1_wagon_kick");

  return p1_hill();
}

static scene jump() {
  game_vars::blinded = false;
  print_file("p1_wagon_jump");

  return p1_hill();
}

static scene wait() {
  print_file("p1_wagon_wait");

  return p1_hill();
}
