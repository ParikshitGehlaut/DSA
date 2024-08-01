#include <iostream>
using namespace std;

typedef struct employee
{
    int eId;      // 4
    char favChar; // 1
    float salary; // 4
    // total of 9 bytes is used
} ep;

union money
{
    /* data */
    int rice;     // 4
    char car;     // 1
    float pounds; // 4
    // union helps in better memory management
};

int main()
{
    ep Harry;
    Harry.eId = 1;
    Harry.favChar = 'H';
    Harry.salary = 1000.0;

    cout << "Harry's ID is " << Harry.eId << endl;
    cout << "Harry's salary is " << Harry.salary << endl;

    union money m1;
    m1.rice = 42;
    m1.car = 'C';
    cout << m1.rice << endl; // now it return garbage value

    enum Meal
    {
        breakfast,
        lunch,
        dinner
    };
    cout << breakfast << endl;
    cout << lunch << endl;
    cout << dinner << endl;
    return 0;
}