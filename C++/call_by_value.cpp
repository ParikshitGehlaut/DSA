#include <iostream>
using namespace std;

void modifyValue(int a)
{
    a = 10; // Changes the local copy, not the original argument
}

int main()
{
    int x = 5;
    modifyValue(x);
    cout << "Value of x after modifyValue: " << x << endl; // Output: 5
    return 0;
}
