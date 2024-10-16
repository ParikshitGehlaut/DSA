#include<iostream>
using namespace std;

class Complex{
    int real;
    int imag;
public:
    void setData(int, int);
    void getData();
};

void Complex::setData(int a, int b){
    real = a;
    imag = b;
}

void Complex::getData(){
    cout << real << " + " << imag << "i" << endl;
}

int main(){
    // Complex c1;
    // Complex *ptr = &c1;

    Complex *ptr = new Complex;

    // (*ptr).setData(3, 4);
    // (*ptr).getData();   is exactly same as below lines 

    ptr->setData(3,4);
    ptr->getData();

    Complex *p = new Complex;

    for(int i=0; i<4; i++){
        (p + i)->setData(i+1, i+2);
        (p + i)->getData();
    }

    return 0;
}