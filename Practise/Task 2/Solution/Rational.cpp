#include "Rational.h"
#include <iostream>
using namespace std;



Rational::Rational(int num,int denom){
    numerator = num;
    denomerator = denom;

}

Rational::Rational(int number){

    numerator = number;
    denomerator = 1;
}

Rational::Rational(){

    denomerator = 1;
    numerator = 0;
}

Rational Rational::add(const Rational& inputNumber){

    Rational outputNumber;
    outputNumber.numerator = denomerator * inputNumber.numerator + inputNumber.denomerator* numerator;
    outputNumber.denomerator = denomerator * inputNumber.denomerator;
    return outputNumber;
}

Rational Rational::subtract(const Rational& inputNumber){

    Rational outputNumber;
    outputNumber.numerator = numerator*inputNumber.denomerator - denomerator*inputNumber.numerator;
    outputNumber.denomerator = denomerator*inputNumber.denomerator;
    return outputNumber;
}

Rational Rational::multiply(const Rational& inputNumber){

    Rational outputNumber;
    outputNumber.numerator = numerator * inputNumber.numerator;
    outputNumber.denomerator = denomerator * inputNumber.denomerator;
    return outputNumber;
}

Rational Rational::divide(const Rational& inputNumber){

    Rational outputNumber;
    outputNumber.numerator = denomerator* inputNumber.numerator;
    outputNumber.denomerator = numerator * inputNumber.denomerator;
    return outputNumber;
}

Rational Rational::opposite(){

    return Rational(-numerator,denomerator);
}

int Rational::getNum(){

    int gcd = GCD(numerator,denomerator);
    return numerator/gcd;
}

int Rational::getDenum(){

    int gcd = GCD(numerator,denomerator);
    return denomerator/gcd;
}

bool Rational::isPos(){

    if ((numerator < 0 && denomerator > 0) || (numerator > 0 && denomerator < 0))
        return false;
    else
        return true;
}

double Rational::toDouble(){

    return numerator/denomerator;
}

void Rational::print(){

    int gcd = GCD(numerator,denomerator);
    cout << numerator/gcd << "/" << denomerator/gcd;
}

int Rational::GCD(int num, int denom){

    if(num%denom == 0){
        return denom;
    }

    return GCD(denom,num%denom);

}
