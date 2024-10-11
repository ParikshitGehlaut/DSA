#include <iostream>
using namespace std;

class Employee
{

public:
    int id;
    float salary;
    Employee(int id)
    {
        this->id = id;
        this->salary = 200;
    }
    Employee() {}
};

/*
Derived class syntax
class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}}
{
    members/methods/etc..
}

Note:
1. default visibility mode is private.
2. Private: public member of base class become private member of derived class.
3. Public: public member of base class become public member of derived class.
4. private member of derived class will never become member of derived class.
*/

class Programmer : public Employee
{
public:
    int languageCode;

    Programmer(int id)
    {
        this->id = id;
        this->languageCode = 9;
    }

    void getData()
    {
        cout << this->id << endl;
    }
};

int main()
{
    Employee Harry(1), Rohan(2);
    Programmer skillF(10);
    skillF.getData();

    return 0;
}