#ifndef _SCENE_H_
#define _SCENE_H_

#include <memory>
#include <string>
#include <vector>

using std::string;
using std::unique_ptr;
using std::vector;

typedef const vector<string>& scene_args;

class scene {
public:
    scene& operator()(void);    
public:
    scene(string fname, scene& (f)(void));
public:
    scene(const scene &that) {copy(that);}
    scene& operator=(scene&);
    scene(scene &&that) {move(std::move(that));}
    scene& operator=(scene&&);
private:
    void copy(const scene& that);
    void move(scene&& that);
private:
    virtual scene& _cli(scene_args) = 0;
private:
    struct impl;
    unique_ptr<impl> _impl;
};

#endif