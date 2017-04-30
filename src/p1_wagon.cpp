#include "p1_wagon.h"
#include "p1_hill.h"
#include "print_file.h"
#include "GameVars.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

static void kick();
static void jump();
static void wait();

void p1_wagon() {
  GameVars::hands_bound = true;
  GameVars::feet_bound = false;
  GameVars::blinded = true;
  
  while(true) {
    int n;
    
    print_file("wagon");
    
    cin >> n;
    
    switch(n) {
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
}

static void kick() {
  GameVars::feet_bound = true;
  print_file("p1_wagon_kick");
  p1_hill();
}

static void jump() {
  GameVars::blinded = false;
  print_file("p1_wagon_jump");
  p1_hill();
}

static void wait() {
  print_file("p1_wagon_wait");
  p1_hill();
}
