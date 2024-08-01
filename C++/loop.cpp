#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i <= 5; i++)
    {
        cout << "i = " << i << std::endl;
    }

    int i = 6;
    while (i <= 10)
    {
        cout << "i = " << i << std::endl;
        i++;
    }
    return 0;
}