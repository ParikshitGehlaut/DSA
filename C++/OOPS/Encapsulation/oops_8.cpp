#include <iostream>
using namespace std;

// Global variable to count number of objects
int count = 0;

class num
{
public:
    // Constructor increments the count and prints a message
    num()
    {
        ::count++;
        cout << "This is the time when constructor is called, for object number " << count << endl;
    }

    // Destructor decrements the count and prints a message
    ~num()
    {
        cout << "This is the time when my destructor is called for object number " << count << endl;
        ::count--;
    }
};

int main()
{
    cout << "We are inside our main " << endl;
    cout << "Creating first object" << endl;
    num n1; // Constructor is called for n1
    cout << endl;
    for (int i = 0; i < 2; i++)
    {

        cout << "Entering the block" << endl;
        cout << "Creating two more objects" << endl;
        num n2, n3; // Constructors are called for n2 and n3
        cout << "Exiting this block" << endl;
    } // Destructors are called for n2 and n3
    cout << endl;
    cout << "Back to main" << endl;
    return 0; // Destructor is called for n1
}
