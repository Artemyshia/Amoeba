#ifndef WIDGET_HH
#define WIDGET_HH
#include "graphics.hpp"

using namespace genv;
using namespace std;

struct Point {
    int x;
    int y;
    int t;

    Point();

    Point(int a, int b, int t);
};

struct Size {
    int w;
    int h;

    Size();

    Size(int a, int b);
};

class Widget {
public:
    Widget(Point pos_ = { 0, 0, 0 }, Size size_ = { 0, 0 });
    virtual ~Widget();

    virtual void draw();
    virtual void action(event evt);

    Point get_pos() const;
    void set_pos(Point new_pos);

    Size get_size() const;
    void set_size(Size new_size);

private:
    Point pos;
    Size size;
};

#endif
