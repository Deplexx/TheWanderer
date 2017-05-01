#ifndef _SCENE_H_
#define _SCENE_H_

#include <functional>
#include <memory>
#include <string>
#include <vector>

using std::function;
using std::string;
using std::unique_ptr;
using std::vector;

typedef scene_args vector<string>&&;

class scene {
public:
    scene operator()(scene_args);    
public:
    scene(string fname, scene (f)(scene_args));
public:
    scene(scene&);
    scene& operator=(scene&);
    scene(scene&&);
    scene& operator=(scene&&);
private:
    void copy(scene &that) {scene(that);}
    void move(scene &&that) {scene(that);}
private:
    virtual scene _cli(scene_args) = 0;
private:
    class scene_impl;
    unique_ptr<scene_impl> _impl;
};

#endif