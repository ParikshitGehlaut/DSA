#include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    Complex()
    {
        cout << "Hey! I am the default constructor of class Complex" << endl;
        a = 10;
        b = 0;
    }

    Complex(const Complex &other)
    {
        cout << "Hey! I am the copy constructor of class Complex" << endl;
        a = other.a;
        b = other.b;
    }

    void printNumber()
    {
        cout << "Your complex number is " << a << " + " << b << "i" << endl;
    }
};

int main()
{
    Complex c1; // This will invoke the constructor
    c1.printNumber();

    Complex c2 = c1; // This will invoke the copy constructor
    c2.printNumber();

    return 0;
}
