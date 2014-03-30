/*
**  The index of the key is the index of the element behind the key.
**  Keys are charecters, elements are integers
**
*/
#ifndef DICTIONARY_H_INCLUDED
#define DICTIONARY_H_INCLUDED

#include <iostream>

using namespace std;

class Dictionary{

public:
    Dictionary();
    Dictionary(const Dictionary&);
    ~Dictionary();
    Dictionary& operator=(const Dictionary&);

    void checkFor(const char);
    void printPercentage() const;


private:
    int size;
    int capacity;

    char* keys;
    int* elements;
    int numOfElements;

    void copyDict(const Dictionary&);
    void extend();
};

#endif // DICTIONARY_H_INCLUDED
