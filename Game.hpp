#ifndef _GAME_H
#define _GAME_H

#include <memory>

using std::unique_ptr;

class Game {  
public:
  void run();
  void quit();
public:
  virtual void save() = 0;
  virtual void load() = 0;
protected:
  class Scene {
  public:
    virtual Scene *run() = 0;
  protected:
    Game &game();
  protected:
    Scene(Game &outer);
  protected:
    static void printFile(const char *fName);
    static void printFile(const std::string &fName);
  private:
    Game &_outer;
  };
protected:
  Game(Scene *init);
private:
  void setTheScene(Scene *next);
private:
  unique_ptr<Scene> _init;
};

#endif
