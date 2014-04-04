#include "Rational.h"
#include <iostream>
#include <cmath>
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

Rational Rational::add(const Rational& inputNumber) const{

    Rational outputNumber;
    outputNumber.numerator = denomerator * inputNumber.numerator + inputNumber.denomerator* numerator;
    outputNumber.denomerator = denomerator * inputNumber.denomerator;
    return outputNumber;
}

Rational Rational::subtract(const Rational& inputNumber) const{

    Rational outputNumber;
    outputNumber.numerator = numerator*inputNumber.denomerator - denomerator*inputNumber.numerator;
    outputNumber.denomerator = denomerator*inputNumber.denomerator;
    return outputNumber;
}

Rational Rational::multiply(const Rational& inputNumber) const{

    Rational outputNumber;
    outputNumber.numerator = numerator * inputNumber.numerator;
    outputNumber.denomerator = denomerator * inputNumber.denomerator;
    return outputNumber;
}

Rational Rational::divide(const Rational& inputNumber) const{

    Rational outputNumber;
    outputNumber.numerator = denomerator* inputNumber.numerator;
    outputNumber.denomerator = numerator * inputNumber.denomerator;
    return outputNumber;
}

Rational Rational::opposite() const{

    return Rational(-numerator,denomerator);
}

int Rational::getNum() const{

    int gcd = GCD(numerator,denomerator);
    return numerator/gcd;
}

int Rational::getDenum() const{

    int gcd = GCD(numerator,denomerator);
    return denomerator/gcd;
}

bool Rational::isPos() const{

    if ((numerator < 0 && denomerator > 0) || (numerator > 0 && denomerator < 0))
        return false;
    else
        return true;
}

double Rational::toDouble() const{

    return numerator/denomerator;
}

void Rational::print() const{

    int gcd = GCD(numerator,denomerator);
    cout << numerator/gcd << "/" << denomerator/gcd;
}

int Rational::GCD(int num, int denom) const{

    if(num%denom == 0){
        return denom;
    }

    return GCD(denom,num%denom);

}

Rational Rational::operator+(const Rational& rat) const{
    return add(rat);
}

Rational Rational::operator-(const Rational& rat) const{
    return subtract(rat);
}

Rational Rational::operator*(const Rational& rat) const{
    return multiply(rat);
}

Rational Rational::operator/(const Rational& rat) const{
    return divide(rat);
}

Rational& Rational::operator+=(const Rational& rat){
    *this = *this + rat;
    return *this;
}

Rational& Rational::operator-=(const Rational& rat){
    *this = *this - rat;
    return *this;
}

Rational& Rational::operator*=(const Rational& rat){
    *this = *this * rat;
    return *this;
}

Rational& Rational::operator/=(const Rational& rat){
    *this = *this / rat;
    return *this;
}

Rational Rational::operator+(const int num) const{
    return *this + Rational(num);
}

Rational Rational::operator-(const int num) const{
    return *this - Rational(num);
}

Rational Rational::operator*(const int num) const{
    return *this * Rational(num);
}

Rational Rational::operator/(const int num) const{
    return *this / Rational(num);
}

Rational operator+(const int num, const Rational rat){
    return Rational(num) + rat;
}

Rational operator-(const int num, const Rational rat){
    return Rational(num) - rat;
}

Rational operator*(const int num, const Rational rat){
    return Rational(num) * rat;
}

Rational operator/(const int num, const Rational rat){
    return Rational(num) / rat;
}

Rational Rational::operator-() const{
    return opposite();
}

bool Rational::operator<(const Rational& rat) const{
    return numerator * rat.denomerator < denomerator * rat.numerator;
}

bool Rational::operator<=(const Rational& rat) const{
    return numerator * rat.denomerator <= denomerator * rat.numerator;
}

bool Rational::operator==(const Rational& rat) const{
    return numerator * rat.denomerator == denomerator * rat.numerator;
}

bool Rational::operator>(const Rational& rat) const{
    return numerator * rat.denomerator > denomerator * rat.numerator;
}

bool Rational::operator>=(const Rational& rat) const{
    return numerator * rat.denomerator >= denomerator * rat.numerator;
}

Rational Rational::operator^(int num) const{
    Rational outputNumber;
    outputNumber.numerator = pow(this->numerator, num);
    outputNumber.denomerator = pow(this->denomerator, num);
    return outputNumber;
}

Rational::operator int() const{
    return (int) numerator/denomerator;
}

Rational::operator double() const{
    return (double) numerator/denomerator;
}

Rational::operator bool() const{
    return numerator;
}

Rational::operator float() const{
    return (float) numerator/denomerator;
}

ostream& operator<<(ostream& os, const Rational& rat){
    os << rat.numerator << "/" << rat.denomerator;
}
