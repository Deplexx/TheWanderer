#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "scene.h"

class game_scene : public scene {
private:    
    scene& _cli(scene_args args) override;
};

void game_run();

#endif
