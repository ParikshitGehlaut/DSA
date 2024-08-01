#include <iostream>
using namespace std;

inline int multiply(int a, int b);

inline int multiply(int a, int b)
{
    return a * b;
}

int main()
{
    int a, b;
    cout << "Enter the value of a and b \n";
    cin >> a >> b;
    cout << "The product of a and b is " << multiply(a, b) << endl;
    cout << "The product of a and b is " << multiply(a, b) << endl;
    cout << "The product of a and b is " << multiply(a, b) << endl;
    cout << "The product of a and b is " << multiply(a, b) << endl;
    return 0;
}