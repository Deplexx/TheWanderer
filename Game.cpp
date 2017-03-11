#include <fstream>
#include <iostream>

#include "Game.hpp"

using std::cout;
using std::endl;
using std::fstream;
using std::unique_ptr;

void Game::run() {
  while(true)
    setTheScene(_init->run());
}

void Game::quit() {
  exit(0);
}

Game &Game::Scene::game() {return _outer;}

Game::Game(Scene *init) : _init(init) {}

void Game::setTheScene(Scene *next) {
  _init.reset(next);
}

Game::Scene::Scene(Game &outer) : _outer(outer) {}

void Game::Scene::printFile(const char *fName) {
  std::fstream fs;

  fs.open(fName);
  cout << fs.rdbuf() << endl << endl;
}

void Game::Scene::printFile(const std::string &fName) {
  Game::Scene::printFile(fName.c_str());
}
