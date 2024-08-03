#include <iostream>
using namespace std;

class MyClass
{
    static int count;

public:
    MyClass()
    {
        count++;
    }

    static void displayCount()
    {
        cout << "Count: " << count << endl;
    }
};

// Initialize static data member
int MyClass::count = 0;

int main()
{
    MyClass obj1, obj2, obj3;

    // Call static method using class name
    MyClass::displayCount();

    // Static method can also be called using an object, though it's not the common practice
    obj1.displayCount();

    return 0;
}
