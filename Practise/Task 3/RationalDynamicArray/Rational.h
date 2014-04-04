#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <iostream>

class Rational{
    public:
        Rational(int,int);
        Rational(int);
        Rational();
        Rational add(const Rational& inputNumber) const;
        Rational subtract(const Rational& inputNumber) const;
        Rational multiply(const Rational& inputNumber) const;
        Rational divide(const Rational& inputNumber) const;
        Rational opposite() const;
        int getNum() const;
        int getDenum() const;
        bool isPos() const;
        double toDouble() const;
        void print() const;

        Rational operator+(const Rational&) const;
        Rational operator-(const Rational&) const;
        Rational operator*(const Rational&) const;
        Rational operator/(const Rational&) const;

        Rational& operator+=(const Rational&);
        Rational& operator-=(const Rational&);
        Rational& operator*=(const Rational&);
        Rational& operator/=(const Rational&);

        Rational operator+(const int) const;
        Rational operator-(const int) const;
        Rational operator*(const int) const;
        Rational operator/(const int) const;

        Rational operator-() const;

        bool operator<(const Rational&) const;
        bool operator<=(const Rational&) const;
        bool operator==(const Rational&) const;
        bool operator>(const Rational&) const;
        bool operator>=(const Rational&) const;

        Rational operator^(int) const;
        Rational operator~() const;

        operator int() const;
        operator double() const;
        operator bool() const;
        operator float() const;

        friend std::ostream& operator<<(std::ostream&, const Rational&);

    private:
        int numerator;
        int denomerator;
        int GCD(int,int) const;
};


#endif // RATIONAL_H_INCLUDED
