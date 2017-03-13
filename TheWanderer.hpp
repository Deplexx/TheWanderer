#ifndef _THEWANDERER_HPP_
#define _THEWANDERER_HPP_

#include "Game.hpp"

#include <memory>
#include <vector>

using std::unique_ptr;
using std::vector;

class TheWanderer : public Game {
public:
  void save() override;
  void load() override;
  void newGame() override;
public:
  TheWanderer();
private:
  enum class _blinding;
  enum class _deafening;
  enum class _silencing;
  
  enum class _handRestraint;
  enum class _footRestraint;
  
  enum class _pursuer;
  
  enum class _brand;
  enum class _item;
private:
  unique_ptr<vector<_blinding>> _blindings;
  unique_ptr<vector<_deafening>> _deafenings;
  unique_ptr<vector<_silencing>> _silencings;
  
  unique_ptr<vector<_handRestraint>> _handRestraints;
  unique_ptr<vector<_footRestraint>> _footRestraints;
  
  unique_ptr<vector<_pursuer>> _pursuers;
  
  unique_ptr<vector<_brand>> _brands;
  unique_ptr<vector<_item>> _items;
private:
  Scene *_initIntro();
  Scene *_initMainMenu();
  Scene *_initStart();
  Scene *_initHill();
  Scene *_initWoods();
  Scene *_initDeepWoods();
};

#endif
