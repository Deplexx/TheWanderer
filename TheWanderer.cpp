#include "TheWanderer.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef TheWanderer w;


enum class  w::_blinding {
  BurlapSack
};
enum class w::_deafening {};
enum class w::_silencing {};

enum class w::_handRestraint {
  Shackles
};
enum class w::_footRestraint {
  Shackles
};

enum class w::_pursuer {
  StartGuards
};

enum class w::_brand {};
enum class w::_item {};


void w::save() {}
void w::load() {}

void w::newGame() {
  _blindings->push_back(_blinding::BurlapSack);
  _handRestraints->push_back(_handRestraint::Shackles);
}


class w::Intro : public Scene {
public:
  Scene *run() override;
public:
  Intro(Game &outer);
};

class w::MainMenu : public Scene {
public:
  Scene *run() override;
public:
  MainMenu(Game &outer);
};

class w::Start : public Scene {
public:
  Scene *run() override;
public:
  Start(Game &outer);
};  


w::Scene *w::Intro::run() {
  Scene::printFile("assets/intro");
  return new MainMenu(game());
}

w::Intro::Intro(Game &outer) : Scene(outer) {}


w::Scene *w::MainMenu::run() {
  while(true) {
    int n;

    cout << "1. New Adventure" << endl;
    cout << "2. Load a Memorized Adventure" << endl;
    cout << endl;

    cin >> n;
    if(n > 2 || n < 1) {
      cout << "Invalid choice." << endl << endl;
      continue;
    }

    cout << endl;

    if(n == 1) {
      game().newGame();
      return new Start(game());
      break;
    } else {
      game().quit();
      break;
    }
  }
  return nullptr;
}

w::MainMenu::MainMenu(Game &outer) : Scene(outer) {}


w::Scene *w::Start::run() {
  int n;
  string pwd = "assets/p1/";
  string cur = pwd + "start_scene/";
  string nxt = pwd + "hill_scene/";

  Scene::printFile(cur + "start");
  while(true) {
    cin >> n;
    switch(n) {
    case 1:
      Scene::printFile(cur + "kick");
      Scene::printFile(nxt + "branded");
    case 2:
      Scene::printFile(cur + "jump");
    case 3:
      Scene::printFile(cur + "wait");
    }
  }
}

w::Start::Start(Game &outer) : Scene(outer) {}


w::TheWanderer() : Game(new Intro(*this)),
		   _blindings(new vector<_blinding>),
		   _deafenings(new vector<_deafening>),
		   _silencings(new vector<_silencing>),
                   _handRestraints(new vector<_handRestraint>),
                   _footRestraints(new vector<_footRestraint>),
                   _pursuers(new vector<_pursuer>),
                   _brands(new vector<_brand>),
                   _items(new vector<_item>) {}

