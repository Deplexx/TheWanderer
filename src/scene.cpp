#include "scene.h"

#include <functional>

using std::function;
using std::make_unique;

//scene::impl
struct scene::impl {
public:
    impl(string fname, scene& (f)(void)):
        _fname(make_unique<string>(fname)),
        _f(make_unique<function<scene&(scene_args)>>(f)) {}
    ~impl() {}
public:
    unique_ptr<string> _fname;
    unique_ptr<function<scene&(scene_args)>> _f;
};

//scene
scene& scene::operator() (void) {
    while(true) {
        print_file(*_impl->_fname);

        return _cli(read_line());
    }
}

scene::scene(string fname, scene& (f)(void)) {
    _impl = make_unique<impl>(fname, f);
}

void scene::copy(const scene &that) {
    _impl = make_unique<impl>(*that._impl->_fname, *that._impl->_f);
}

scene& scene::operator=(scene &that) {
    if(this != &that)
        copy(that);

    return *this;
}

void scene::move(scene &&that) {
    _impl = that._impl;
}

scene& scene::operator=(scene &&that) {
    if(this != &that)
        move(std::move(that));

    return *this;
}