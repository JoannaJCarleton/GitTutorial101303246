#ifndef TAARRAY_H
#define TAARRAY_H
#include "TextArea.h"

#define MAX_ARR 64

class TAArray{

    public:

    TAArray();
    ~TAArray();
    bool add(TextArea* ta);
    bool add(TextArea* ta, int index);
    TextArea* get(string name) const;
    TextArea* get(int index) const;

    TextArea* remove(string name);
    TextArea* remove(int index);


    bool isFull(){return size == MAX_ARR;}
    int getSize(){return size;}
    void print();

    private:

    TextArea** elements;
    int size;
};

#endif