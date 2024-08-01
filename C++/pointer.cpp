#include <iostream>

using namespace std;

int main()
{
    // Pointer --> data type which stores the address of other data types

    int a = 5;
    int *b = &a;
    // & operator --> (address of) data type
    cout << "the address of a is " << &a << endl;
    cout << "the address of a is " << b << endl;

    // * --> (value at) derefernce operator
    cout << "The value at address b is " << *b << endl;
    cout << "The value at address b is " << a << endl;

    // Pointer to Pointer
    int **c = &b;
    cout << "The address of b is " << c << endl;
    cout << "The address of b is " << &b << endl;
    cout << "The value at address c is " << *c << endl;
    cout << "The value at address c is " << b << endl;
    cout << "The value_at(value_at(c)) i.e. a is " << **c << endl;

    return 0;
}