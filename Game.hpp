#ifndef _GAME_H
#define _GAME_H

#include <functional>
#include <memory>

using std::unique_ptr;

class Game {  
public:
  void run();
  void quit();
public:
  virtual void save() = 0;
  virtual void load() = 0;
  virtual void newGame() = 0;
protected:
  class Scene;
protected:
  Game(Scene *init);
private:
  void setTheScene(Scene *next);
private:
  unique_ptr<Scene> _init;
};

class Game::Scene {
public:
  Scene *run();
public:
  Scene(std::function<Scene*()> run);
public:
  static void printFile(const char *fName);
  static void printFile(const std::string &fName);
private:
  std::function<Scene*()> _run;
};

#endif
