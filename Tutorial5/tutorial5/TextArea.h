#ifndef TEXTAREA_H
#define TEXTAREA_H
#include <string>
#include <X11/Xlib.h>
#include "RGB.h"
#include "defs.h"
#include <iostream>

using namespace std;


class TextArea{

    public:

    TextArea(int x, int y, int width, int height, const string& id, const string& label);
    TextArea(Rectangle rectangle, const string& id, const string& label);
    TextArea();
    TextArea(const TextArea& ta);
    void draw(Display *display, Window win, GC gc, int x, int y) const;
    bool overlaps(const TextArea& ta) const;
    void print() const;
    void setFill(const RGB& rgb);
    void setBorder(const RGB& rgb);
    bool equals(string id);
    

    private:

    Rectangle dimensions;
    string text;
    string id;
    RGB fill;
    RGB border;
};

#endif