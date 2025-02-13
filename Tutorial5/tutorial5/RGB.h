// defining RGB.H file 

#ifndef RGB_H
#define RGB_H
#include "defs.h"

// creating rgb class 
class RGB{

    // creating all the signatures for the public functions 
    public:

    RGB(int rValue, int gValue, int bValue);
    RGB(CuColour value);
    RGB();
    CuColour getColour() const;
    void setColour( CuColour colourValue);
    int getR() const;
    int getG() const;
    int getB() const;
    static RGB WHITE();
    static RGB BLACK();
    static RGB RED();
    static RGB GREEN();
    static RGB BLUE();

    // creating all the private variables 
    private:

    int r;
    int g;
    int b;

};

// ending definition 
#endif