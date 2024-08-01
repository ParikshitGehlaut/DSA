#include <iostream>
using namespace std;

void modifyValue(int *a)
{
    *a = 10;
}

int main()
{
    int x = 5;
    modifyValue(&x);
    cout << "Value of x after modifyValue: " << x << endl; // Output: 10
    return 0;
}
