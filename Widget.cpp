#include "Widget.hh"

using namespace genv;
using namespace std;


Point::Point(){
}

Point::Point(int a, int b, int c){
    x=a;
    y=b;
    t=c;
}

Size::Size(){
}

Size::Size(int a,int b){
    w=a;
    h=b;
}


Widget::Widget(Point pos_, Size size_){
    pos = pos_;
    size = size_;
}

Widget::~Widget() {
}

void Widget::draw() {
}

void Widget::action(event evt){
}

Point Widget::get_pos() const {
    return pos;
}

void Widget::set_pos(Point new_pos) {
    pos = new_pos;
}

Size Widget::get_size() const {
    return size;
}

void Widget::set_size(Size new_size) {
    size = new_size;
}
