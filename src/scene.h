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

class scene;
typedef const vector<string>& scene_args;
typedef unique_ptr<scene> (scene_func_ptr)(scene_args);
typedef function<unique_ptr<scene>(scene_args)> scene_func;

class scene {
public:    
    scene();
    scene(scene_func);
    scene(string fname, scene_func_ptr);
    scene(string fname, scene_func);
public:    
    virtual unique_ptr<scene> operator()() = 0;
protected:
    virtual unique_ptr<scene> _cli(scene_args) = 0;
protected:
    string _fname;
    scene_func _func;
};

#endif