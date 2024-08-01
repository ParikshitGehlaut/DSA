#include <iostream>

using namespace std;

int main()
{
    int marks[4] = {45, 23, 99, 12};

    for (int i = 0; i < 4; i++)
    {
        cout << marks[i] << endl;
    }

    // arrays using pointer
    cout << "Printing arrays using pointers" << endl;
    int size = sizeof(marks) / sizeof(marks[0]);
    int *ptr = &marks[0];
    for (int i = 0; i < size; i++)
    {
        cout << *(ptr + i) << endl;
    }

    return 0;
}