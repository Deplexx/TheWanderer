#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "scene.h"

class game_scene : public scene {
private:
    unique_ptr<scene> operator()() override;
    unique_ptr<scene> _cli(scene_args args) override;
public:
    game_scene() : scene() {}
    game_scene(scene_func f) : scene(f) {}
    game_scene(string fname, scene_func_ptr f) : 
        scene(fname, f) {}
    game_scene(string fname, scene_func f) : 
        scene(fname, f) {}
};

void game_run();

#endif
