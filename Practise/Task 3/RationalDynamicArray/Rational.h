#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <iostream>

class Rational{
    public:
        Rational(int,int);
        Rational(int);
        Rational();
        Rational add(const Rational& inputNumber);
        Rational subtract(const Rational& inputNumber);
        Rational multiply(const Rational& inputNumber);
        Rational divide(const Rational& inputNumber);
        Rational opposite();
        int getNum();
        int getDenum();
        bool isPos();
        double toDouble();
        void print();

    private:
        int numerator;
        int denomerator;
        int GCD(int,int);
};


#endif // RATIONAL_H_INCLUDED
