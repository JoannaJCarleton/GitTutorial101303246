#include "TextArea.h"
#include <iostream>

using namespace std;

TextArea::TextArea(int x, int y, int width, int height, const string& id, const string& label){
    
    dimensions.x = x;
    dimensions.y = y;
    dimensions.width = width;
    dimensions.height = height;
    this->id = id;
    text = label;
    fill =  RGB(255,255,255);
    border =  RGB(0,0,0);

}

TextArea::TextArea(Rectangle rectangle, const string& id, const string& label){
    
    dimensions = rectangle;
    this->id = id;
    text = label;
    fill = RGB(255,255,255);
    border = RGB(0,0,0);

}

TextArea::TextArea(){

    dimensions.x = 0;
    dimensions.y = 0;
    dimensions.width = 0;
    dimensions.height = 0;
    id = " ";
    text = " ";
    fill =  RGB(0,0,0);
    border = RGB(0,0,0);

}

TextArea::TextArea(const TextArea& ta){
    
    dimensions = ta.dimensions;
    id = ta.id;
    text = "DUPLICATE";
    fill =  ta.fill;
    border = ta.border;

}

void TextArea::draw(Display *display, Window win, GC gc, int x, int y) const{
    // specifications said not needed 
}

bool TextArea::overlaps(const TextArea& ta) const{

    if(dimensions.overlaps(ta.dimensions)){
        
        // returning false if overlap not detected 
        return true;
    }
    
    // returning true for overlap 
    return false;
}

void TextArea::print() const{

    cout<<"TextArea id: "<<id<<endl;
    cout<<"Preferred location: "<<dimensions.x<<", "<<dimensions.y<<endl;
    cout<<"Size: "<<dimensions.width<<", "<<dimensions.height<<endl;
    cout<<"Text: "<<text<<endl; 
}

void TextArea::setFill(const RGB& rgb){
    fill = rgb;
}
void TextArea::setBorder(const RGB& rgb){
    border = rgb;
}

bool TextArea::equals(string id){
    return this->id == id;
}