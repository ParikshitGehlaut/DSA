#include<iostream>
using namespace std;

int main(){
    int const x = 10;
    int const *ptr = &x;
    // *ptr = 20;  gives error becoz x is const
    // x = 10;  gives error bcoz x is const

    int y = 20;
    int const *p = &y;

    y = 30; // since y is not const, it will not give error 

    //*p = 40; but modify y using p pointer will give error 
    cout << y << endl;
    return 0;
}