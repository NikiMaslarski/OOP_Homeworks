#ifndef RATIONALDYNAMICARRAY_H_INCLUDED
#define RATIONALDYNAMICARRAY_H_INCLUDED

#include <iostream>
#include "Rational.h"

class RatDynArr{

    public:
        RatDynArr();
        RatDynArr(const RatDynArr&);
        RatDynArr& operator=(const RatDynArr&);
        ~RatDynArr();

        void push(const Rational&);
        void insertAt(int,const Rational&);
        void pop();
        void removeAt(int);
        Rational& get(int);
        const Rational& get(int) const;
        void set(int, const Rational&);
        int getSize();

    private:
        Rational* dynArr;
        int arrSize;
        int capacity;

        void copyRatDynArr(const RatDynArr&);
        void dynamic();

};


#endif // RATIONALDYNAMICARRAY_H_INCLUDED
