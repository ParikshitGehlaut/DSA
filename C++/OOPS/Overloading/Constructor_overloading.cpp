#include<iostream>
using namespace std;

class Complex{
    int a, b;
public: 
    Complex(){
        a = 0;
        b = 0;
    }

    Complex(int n1, int n2){
        a = n1;
        b = n2;
    }

    Complex(int n1){
        a = n1;
        b = 0;
    }

    void printNumber(){
        cout << "Your Number is " << a << " + " << b << "i" << endl;
    }
};

int main(){
    Complex c1(3), c2(3, 4), c3;

    c1.printNumber();
    c2.printNumber();
    c3.printNumber();
    return 0;
}