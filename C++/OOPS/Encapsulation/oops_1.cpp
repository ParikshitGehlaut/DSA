#include <iostream>
using namespace std;

class Employee
{
private:
    int a, b, c;
    //   only function can access it.
public:
    int d, e;
    void setData(int a1, int b1, int c1)
    {
        a = a1;
        b = b1;
        c = c1;
    }
    void getData()
    {
        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
        cout << d << endl;
        cout << e << endl;
    }
};

int main()
{
    Employee harry;
    harry.d = 4;
    harry.e = 5;
    harry.setData(1, 2, 3);
    harry.getData();
    return 0;
}