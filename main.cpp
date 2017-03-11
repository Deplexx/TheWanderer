#include <fstream>
#include <iostream>

#include <memory>
#include <vector>

#include <stdint.h>

#include "Game.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::unique_ptr;
using std::string;
using std::vector;

class TheWanderer : public Game {
  void save() override {}
  void load() override {}
  
  class Intro : public Scene {
  public:
    Scene *run() override {
      Scene::printFile("assets/intro");
      return new MainMenu(game());
    }
  public:
    Intro(Game &outer) : Scene(outer) {}
  };

  class MainMenu : public Scene {
  public:
    Scene *run() override {
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
	  return new Start(game());
	  break;
	} else {
	  game().quit();
	  break;
	}
      }
      return nullptr;
    }
  public:
    MainMenu(Game &outer) : Scene(outer) {}
  };

  
  class Start : public Scene {
  public:
    Scene *run() override {
      int n;      
      string cur("assets/p1/start_scene/");
      
      Scene::printFile(cur + "start");
      while(true) {
	cin >> n;
        switch(n) {
	case 1:
	  Scene::printFile(cur + "kick");
	  return new HillGuardsAngry(game());
	case 2:
	  Scene::printFile(cur + "jump");
 	  return new HillGuardsOffGuard(game()); 
	case 3:
	  Scene::printFile(cur + "wait");
 	  return new HillGuardsNormal(game());
	default:
	  cout << "Invalid choice." << endl << endl;
        }
      }
    }
  public:
    Start(Game &outer) : Scene(outer) {}
  };
  
  class Hill : public Scene {
  public:
    Scene *run() {
      Scene::printFile("assets/p1/hill_scene/hill");
      return run_inner();
    }
  protected:
    virtual Scene *run_inner() = 0;
  public:
    Hill(Game &outer) : Scene(outer) {}  
  };

  class HillGuardsAngry : public Hill {
  public:
    Scene *run_inner() {
      return nullptr;
    }
  public:
    HillGuardsAngry(Game &outer) : Hill(outer) {}
  };

  class HillGuardsNormal : public Hill {
  public:
    Scene *run_inner() {
      return nullptr;
    }
  public:
    HillGuardsNormal(Game &outer) : Hill(outer) {}
  };
  
  class HillGuardsOffGuard : public Hill {
  public:
    Scene *run_inner() {
      return nullptr;
    }
  public:
    HillGuardsOffGuard(Game &outer) : Hill(outer) {}
  };  
public:
  TheWanderer() : Game(new Intro(*this)) {}
};

TheWanderer tw = TheWanderer();

int main(int argc, char *argv[]) {
  tw.run();
  
  return 0;
}

