#include<iostream>
using namespace std;

class Complex;

class Calculator{
public:
    int add(int a, int b){
        return (a + b);
    }

    int sumRealComplex(Complex, Complex);
    int sumCompComplex(Complex, Complex);
};

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
    // Indiviadually declaring each function as a friend 
    // friend int Calculator :: sumRealComplex(Complex c1, Complex c2);
    // friend int Calculator :: sumCompComplex(Complex c1, Complex c2);

    // Alternate: declaring whole class as a friend
    friend class Calculator;
};

int Calculator :: sumRealComplex(Complex c1, Complex c2){
    return (c1.a + c2.a);
}

int Calculator :: sumCompComplex(Complex c1, Complex c2){
    return (c1.b + c2.b);
}

int main(){
    Complex c1, c2;

    c1.setNumber(3, 4);
    c2.setNumber(5, 4);

    Calculator calc;

    int resr = calc.sumRealComplex(c1, c2);
    cout << resr << endl;
    int resc = calc.sumCompComplex(c1, c2);
    cout << resc << endl;
    return 0;
}