#include "scene.h"

//scene_impl
scene::scene_impl {
public:
    scene_impl(string fname, scene (f)(void));
public:
    string fname;
    function<scene(scene_args)> f;
};

scene::scene_impl(string fname, scene (f)(void)) :
    _fname(fname), _f(f) {}

//scene
scene scene::operator() (void) {
    while(true) {
        print_file(_impl.fname);

        return _cli(read_line());
    }
}

scene::scene(string fname, scene (f)(void)) {
    _impl = unique_ptr<scene_impl>(new scene_impl(fname, f));
}

scene::scene(scene &that) {
    _impl = unique_ptr<scene_impl>(
        new scene_impl(that._impl->fname, that._impl->f)
    );
}

scene& scene::operator=(scene &that) {
    if(this != &that)
        copy(that);

    return *this;
}

scene::scene(scene &&that) {
    _impl = that._impl;
}

scene& scene::operator=(scene &&that) {
    if(this != &that)
        move(that);

    return *this;
}