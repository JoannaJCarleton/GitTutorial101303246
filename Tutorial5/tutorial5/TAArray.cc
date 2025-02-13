#include "TAArray.h"
#include <iostream>
using namespace std;

TAArray::TAArray(){
    size = 0;
    elements = new TextArea*[MAX_ARR];
}

TAArray::~TAArray(){
    delete [] elements;
}

bool TAArray::add(TextArea*ta){

    if (size >= MAX_ARR)return false;
    elements[size] = ta;
    size++;
    return true;
}

bool TAArray::add(TextArea* ta, int index){
   
   if (size >= MAX_ARR)return false;

    for (int i = size; i > index ; --i){
        elements[i]= elements[i-1];
    }

    elements[index] = ta;
    size++;
    return true;
}


TextArea* TAArray::get(string id) const{
    for (int i = 0; i < size; ++i){
        if (elements[i]->equals(id)){
            return elements[i];
        }
    }
    return NULL;
}

TextArea* TAArray::get(int index) const{
    if (index < 0 || index >= size) return NULL;
    return elements[index];
}

TextArea* TAArray::remove(string number){
    
    int index = 0;
    //we want to find the index of the element to remove
    while (!elements[index]->equals(number) && index < size){
        ++index;
    }

    return remove(index);

}

TextArea* TAArray::remove(int index){

    if (index<0 || index >=size) return nullptr;

    //we have found what we wanted to remove,
    //assign the output value
    TextArea *ta = elements[index];

    //copy everything after index left one position
    while (index < size - 1){
        elements[index] = elements[index + 1];
        ++index;
    }
    --size;
    return ta;

}


void TAArray::print()
{
  cout << endl << endl << "Text Areas:" << endl;
  for (int i=0; i<size; ++i)
    elements[i]->print();

  cout << endl;
}