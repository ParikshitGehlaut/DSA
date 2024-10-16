#include<iostream>
using namespace std;

class Complex{
    int a, b;
public:
    void setNumber(int n1, int n2){
        a = n1;
        b = n2;
    }

    void printNumber(){
        cout << "Your Number is " << a << " + " << b << "i" << endl;
    }

    friend Complex sumComplex(Complex c1, Complex c2);
};

Complex sumComplex(Complex c1, Complex c2){
    Complex c3;
    c3.setNumber(c1.a + c2.a , c1.b = c2.b);
    return c3;
}

int main(){
    Complex c1, c2;

    c1.setNumber(3, 4);
    c2.setNumber(5, 4);

    Complex c3 = sumComplex(c1, c2);
    c3.printNumber();
    return 0;
}