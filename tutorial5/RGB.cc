#include "RGB.h"

// rgb constructor to initialize all values with given values 
RGB::RGB(int red, int green, int blue){

    // initializing values 
    if((red >= 0) && (red <= 255) && (blue >=0) && (blue <= 255) && (green >= 0) && (green <= 255)){
        r = red;
        g = green;
        b = blue;
    }
    else{
        r = 0;
        g = 0;
        b = 0;
    }

}

// rgb constructor to initialize all values based on cucolour 
RGB::RGB(CuColour colourValue){

    if(((colourValue >> (16)) & 0xFF >= 0) && ((colourValue >> (16)) & 0xFF <= 255) && (colourValue & 0xFF >=0) && (colourValue & 0xFF <= 255) && ((colourValue >> (8)) & 0xFF >= 0) && ((colourValue >> (8)) & 0xFF <= 255)){
        
        // setting variables using bitmasking 
        r =  (colourValue >> (16)) & 0xFF;
        g =  (colourValue >> (8)) & 0xFF;
        b =  colourValue & 0xFF;
    }
    else{
        r = 0;
        g = 0;
        b = 0;
    }

}

// default constructor to intitialize all values to 0
RGB::RGB(){

    // setting all values to 0
    r = 0;
    g = 0;
    b = 0;
}

// function to return cuColour using rgb values 
CuColour RGB:: getColour() const{

    // creating new cucolour value 
    CuColour newCuColour = 0;

    // using bitmasking to set rgb values into right position 
    newCuColour |= (r << 16);
    newCuColour |= (g << 8);
    newCuColour |= (b << 0);

    // returning new cucolour value 
    return newCuColour;

}

// function to set rgb values based on cu colour 
void RGB:: setColour( CuColour colourValue){

    // setting rgb values using bitmasking 
    r =  (colourValue >> (16)) & 0xFF;
    g =  (colourValue >> (8)) & 0xFF;
    b =  (colourValue >> (0)) & 0xFF;

}

int RGB::getR() const{
    return r;
}

int RGB::getG() const{
    return g;
}

int RGB::getB() const{
    return b;
}

RGB RGB::WHITE(){
    return RGB(255,255,255);
}
RGB RGB::BLACK(){
    return RGB(0,0,0);
}
RGB RGB::RED(){
    return RGB(255,0,0);
} 
RGB RGB::GREEN(){
    return RGB(0,255,0);
}
RGB RGB::BLUE(){
    return RGB(0,0,255);
}