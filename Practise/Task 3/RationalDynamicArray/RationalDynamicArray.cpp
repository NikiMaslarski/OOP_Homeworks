#include "RationalDynamicArray.h"

#include <iostream>
#include <cstring>

void RatDynArr::copyRatDynArr(const RatDynArr& arr){

    this->capacity = arr.capacity;
    this->arrSize = arr.arrSize;
    this->dynArr = new Rational[this->capacity];

    for (int i = 0; i < this->arrSize; i++){
        this->dynArr[i] = arr.dynArr[i];
    }
}

RatDynArr::RatDynArr(){

    capacity = 4;
    arrSize = 0;
    dynArr = new Rational[capacity];
}

RatDynArr::RatDynArr(const RatDynArr& arr){

    this->copyRatDynArr(arr);
}

RatDynArr& RatDynArr::operator=(const RatDynArr& arr){

    if (this != &arr){
        if (dynArr != NULL)
            delete []dynArr;

        copyRatDynArr(arr);
    }
    return *this;
}

RatDynArr::~RatDynArr(){
        delete []dynArr;
}

void RatDynArr::dynamic(){
    // Да оправя!
    if(this->arrSize == capacity){
        Rational copyOfArray[arrSize];
        for(int i = 0; i < arrSize; i++){
                copyOfArray[i] = dynArr[i];
        }

        capacity *= 2;
        delete []this->dynArr;

        dynArr = new Rational[capacity];
        for(int i = 0; i < arrSize; i++){
            this->dynArr[i] = copyOfArray[i];
        }
    }
}

void RatDynArr::push(const Rational& rational){

    this->dynArr[this->arrSize] = rational;
    this->arrSize++;
    dynamic();
}

void RatDynArr::insertAt(int index,const Rational& rational){

    Rational temp;

    for(int i = this->arrSize; i >= index; i--){
        this->dynArr[i+1] = this->dynArr[i];
    }

    this->dynArr[index] = rational;
    this->arrSize++;
    this->dynamic();
}

void RatDynArr::pop(){

    this->dynArr[this->arrSize - 1] = 0;
    this->arrSize--;
}

void RatDynArr::removeAt(int index){

    for(int i = index - 1; i < this->arrSize; i++){
        this->dynArr[i] = this->dynArr[i+1];
    }
    this->dynArr[this->arrSize] = 0;
    this->arrSize--;
}

Rational& RatDynArr::get(int index){
    return this->dynArr[index];
}

const Rational& RatDynArr::get(int index) const{
    return this->dynArr[index];
}

void RatDynArr::set(int index, const Rational& rational){
    this->dynArr[index] = rational;
}

int RatDynArr::getSize() const{
    return this->arrSize;
}

Rational& RatDynArr::operator[](int i){
    return this->dynArr[i];
}

RatDynArr& RatDynArr::operator<<(const Rational& rat){
    this->push(rat);
    return *this;
}

RatDynArr& RatDynArr::operator>>(Rational& rat){
    rat =  get(getSize() - 1);
    this->pop();
    return *this;
}

RatDynArr& RatDynArr::operator<<(const RatDynArr& arr){
    int size = arr.getSize();

    for (int i = 0; i < size; i++){
        this->push(arr.get(i));
    }
    return *this;
}

RatDynArr::operator bool() const{
    return this->getSize();
}

RatDynArr& RatDynArr::operator()(Rational (*func)(Rational)){
    int size = this->getSize();
    for(int i = 0; i < size; i++){
        this->set(i, func(get(i)));
    }
    return *this;
}
