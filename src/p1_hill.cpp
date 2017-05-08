#include "p1_hill.h"
#include "game_vars.h"

#include "scene.h"

#include <iostream>
#include <memory>

unique_ptr<scene> p1_hill(scene_args args) {
  return std::make_unique<game_scene>();
}