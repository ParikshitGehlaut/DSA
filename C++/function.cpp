#include <iostream>
using namespace std;

// Function prototypes
int add(int, int);
int multiply(int, int);

int main()
{
    int sum = add(3, 4);          // Function call to add
    int product = multiply(3, 4); // Function call to multiply
    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;
    return 0;
}

// Function definitions
int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}
