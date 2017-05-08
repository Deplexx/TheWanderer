#include "game.h"
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

using std::make_unique;

static void save();
static unique_ptr<scene> main_menu(scene_args);

//game_scene
unique_ptr<scene> game_scene::operator()() {
  unique_ptr<scene> ret;  

  print_file(_fname);

  while(!(ret = _cli(read_line()))); return ret;
}

unique_ptr<scene> game_scene::_cli(scene_args args) {
  //TODO implement game cli logic
  return nullptr;
}


//game
unique_ptr<scene> s = make_unique<game_scene>("intro", main_menu);

void game_run() {
  while(true) {
    s = (*s)();
  }
}

void save() {}

static unique_ptr<scene> main_menu(scene_args args) {
  int n;

  cout << "1. New Adventure" << endl;
  cout << "2. Load a Memorized Adventure" << endl;
  cout << endl;
  
  n = std::stoi(args.at(0));

  if(n == 1) //new game
    return make_unique<game_scene>("p1_wagon_main", p1_wagon);
  else if(n == 2) // load game
    return make_unique<game_scene>();
  else return make_unique<game_scene>();
}
