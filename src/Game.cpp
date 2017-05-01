#include "game.h"
#include "game_vars.h"
#include "p1_wagon.h"
#include "print_file.h"
#include "read_line.h"
#include "scene.h"

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

static void save();
static scene load();
static scene new_game();

static void intro();
static void main_menu();

scene game_scene::_cli(scene_args args) {
  //@TODO implement game cli logic
  return this;
}

scene s = game_scene("intro", intro);

void game_run() {
  while(true) {
    s = s();
  }
}

void save() {}

void load() {}

void new_game() {
  game_vars::intro_complete = false;

  p1_wagon();
}

static void intro() {
  print_file("intro");

  return main_menu();
}

static scene main_menu() {  
  while(true) {
    int n;
      
    cout << "1. New Adventure" << endl;
    cout << "2. Load a Memorized Adventure" << endl;
    cout << endl;
    
    if(n == 1)
      return scene(new_game);
    else if(n == 2)
      return scene(load);
    else exit(0);
  }
}
