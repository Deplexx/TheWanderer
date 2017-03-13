#include "TheWanderer.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef TheWanderer w;

enum class w::_blinding {
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

enum class w::_brand {
  Traitor
};
enum class w::_item {
  LinenRucksack, StaleConvection
};


void w::save() {}
void w::load() {}

void w::newGame() {
  _blindings->push_back(_blinding::BurlapSack);
  _handRestraints->push_back(_handRestraint::Shackles);
}

w::TheWanderer() : Game(_initIntro()),
		   _blindings(new vector<_blinding>),
		   _deafenings(new vector<_deafening>),
		   _silencings(new vector<_silencing>),
                   _handRestraints(new vector<_handRestraint>),
                   _footRestraints(new vector<_footRestraint>),
                   _pursuers(new vector<_pursuer>),
                   _brands(new vector<_brand>),
                   _items(new vector<_item>) {}

w::Scene *w::_initIntro() {
  return new Scene([&]()->Scene *{
    Scene::printFile("assets/intro");
    return _initMainMenu();
  });
}

w::Scene *w::_initMainMenu() {
  return new Scene([&]()->Scene *{
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
	newGame();
	return _initStart();
      } else
	quit();
    }
    return nullptr;
  });
}

w::Scene *w::_initStart() {
  return new Scene([&]()->Scene *{
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
	_brands->push_back(_brand::Traitor);
	_items->push_back(_item::LinenRucksack);	
	_items->push_back(_item::StaleConvection);
	return _initDeepWoods();
      case 2:
	Scene::printFile(cur + "jump");
	_blindings->pop_back();
	return _initHill();
      case 3:
	Scene::printFile(cur + "wait");
      }
    }
  });
}

w::Scene *w::_initHill() {
  quit();
}

w::Scene *w::_initWoods() {
  quit();
}

w::Scene *w::_initDeepWoods() {
  quit();
}
