#include <iostream> // header file

int main()
{
    /*
    std is namespace where all standard identifiers are defined
    cout --> Character output
    This is the standard character output stream in the C++ Standard Library
    */
    std::cout << "Hello, World!" << std::endl;               // print Hello, World to the console, followed by newline
    std::cout << "The value of pi is " << 3.14 << std::endl; // output string and floating point value
    int x = 42;

    std::cout << "The value of x is " << x << std::endl; // output string and variable
    return 0;                                            // End of the main function
}
