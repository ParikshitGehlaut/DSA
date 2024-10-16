#include<iostream>
using namespace std;

class Increase{
    int value;

public:
    Increase(){
        value = 10;
    }

    void operator ++(){
        value = value + 1;
    }
        
    void display(){
        cout <<  "value is : " <<  value << endl;
    }
};

int main(){
    Increase Inc;
    ++Inc;
    Inc.display();
    return 0;
}