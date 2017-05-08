#include "scene.h"

#include "print_file.h"
#include "read_line.h"

#include <functional>

using std::function;

using std::make_unique;

scene::scene() : 
    scene("", [](scene_args args) {return nullptr;}) {}

scene::scene(scene_func func) : scene("", func) {}

scene::scene(string fname, scene_func_ptr func) :
    _fname(fname), _func(func) {}

scene::scene(string fname, scene_func func) :
    _fname(fname), _func(func) {}