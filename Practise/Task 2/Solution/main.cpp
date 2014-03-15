#include <iostream>
#include "Rational.h"

using namespace std;

int main()
{
    Rational a;
    a = Rational(8,4);
    Rational b = Rational(10,20);
    a.print();
    cout <<  " + ";
    b.print();
    Rational c = a.add(b);
    cout << endl;
    c.print();

}
