#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex() : real(0), imag(0) {}

    Complex(double r, double i) : real(r), imag(i) {}

    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }

    Complex operator +(Complex c1){
        Complex temp;
        temp.real = real + c1.real;
        temp.imag = imag + c1.imag;

        return temp;
    }
    Complex operator -(Complex c1){
        Complex temp;
        temp.real = real - c1.real;
        temp.imag = imag - c1.imag;

        return temp;
    }
};

int main() {
    Complex c1(3.4, 2.5);  // 3.4 + 2.5i
    Complex c2(1.2, -3.7); // 1.2 - 3.7i

    cout << "First Complex number: ";
    c1.display();

    cout << "Second Complex number: ";
    c2.display();

    Complex sum = c1 + c2;
    cout << "Sum: ";
    sum.display();

    Complex difference = c1 - c2;
    cout << "Difference: ";
    difference.display();

    return 0;
}
