#include "Game.h"
#include "p1_wagon.h"
#include "GameVars.h"
#include "print_file.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

static void intro();
static void main_menu();

void run() {
  intro();
}

void save() {}
void load() {}
void new_game() {
  p1_wagon();
}

static void intro() {
  print_file("intro");
  main_menu();
}

static void main_menu() {  
  while(true) {
    int n;
      
    cout << "1. New Adventure" << endl;
    cout << "2. Load a Memorized Adventure" << endl;
    cout << endl;
    
    if(n == 1)
      new_game();
    else if(n == 2)
      load();
    else exit(0);
  }
}
