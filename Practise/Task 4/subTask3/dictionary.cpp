#include "dictionary.h"
#include <iomanip>

void Dictionary::copyDict(const Dictionary& oldDict){

    numOfElements = oldDict.numOfElements;
    capacity = oldDict.capacity;
    size = oldDict.size;
    keys = new char[capacity];
    elements = new int [capacity];

    for(int i = 0; i < size; i++){
        keys[i] = oldDict.keys[i];
        elements[i] =oldDict.elements[i];
    }
}

// Мн кофти написана функция...
void Dictionary::extend(){
    if(size == capacity){
        this->capacity *= 2;
        Dictionary temp = Dictionary(*this);

        delete []keys;
        delete []elements;
        keys = NULL;
        elements = NULL;

        this->copyDict(temp);
    }
}


Dictionary::Dictionary(): size(0), capacity(4),
    keys(NULL), elements(NULL), numOfElements(0){

    keys = new char[capacity];
    elements = new int[capacity];
};


Dictionary::Dictionary(const Dictionary& dict){

    this->copyDict(dict);
}

Dictionary::~Dictionary(){

    delete []keys;
    keys = NULL;
    delete []elements;
    elements = NULL;
}

Dictionary& Dictionary::operator=(const Dictionary& dict){

    if(this != &dict){

        if(keys != NULL)
            delete []keys;
        if(elements != NULL)
            delete []elements;

        this->copyDict(dict);
    }
    return *this;
}

void Dictionary::checkFor(char key){
    bool isIn = false;
    for (int i = 0; i < this->size+1; i++){
        if(keys[i] == key){
            elements[i] += 1;
            numOfElements++;
            isIn = true;
            break;
        }
    }
    if(!(isIn)){
        elements[size] = 1;
        keys[size] = key;
        numOfElements++;
        size++;
        extend();
    }
}


void Dictionary::printPercentage() const{

    float percantage;
    cout.precision(4);
    for(int i = 0; i < size; i++){
        percantage = 0;
        percantage = (elements[i] * 100.0) / numOfElements;
        cout << "Element " << keys[i] << ": " << percantage << "%" << endl;
    }

}
