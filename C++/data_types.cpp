#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    cout << "Exploring data types in C++" << endl;
    int a = 4, b = 5;
    cout << "The value of a and b is " << a << " and " << b << endl;
    std::cout << "The size of int32_t is " << sizeof(int32_t) << " bytes." << std::endl;
    std::cout << "The size of int64_t is " << sizeof(int64_t) << " bytes." << std::endl;
    std::cout << "The size of char is " << sizeof(char) << " bytes." << std::endl;

    return 0;
}