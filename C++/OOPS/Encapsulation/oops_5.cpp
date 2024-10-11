#include <iostream>
using namespace std;

class Employee
{
    int Id;
    string name;
    int salary;

public:
    void setInfo(void)
    {
        cout << "Enter the Id of the Employee" << endl;
        cin >> Id;
        cout << "Enter the name of the Employee" << endl;
        cin >> name;
        salary = 10000;
    }

    void getInfo(void)
    {
        cout << "Id " << Id << " name " << name << endl;
    }
};

int main()
{
    Employee fb[4];

    for (int i = 0; i < 4; i++)
    {
        fb[i].setInfo();
    }
    for (int i = 0; i < 4; i++)
    {
        fb[i].getInfo();
    }
    return 0;
}