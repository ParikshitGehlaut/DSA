#include <iostream>
using namespace std;

class Student
{
protected:
    int roll_number;

public:
    void set_roll_number(int);
    void get_roll_number(void);
};

void Student ::set_roll_number(int r)
{
    this->roll_number = r;
}

void Student ::get_roll_number()
{
    cout << "The roll number is " << this->roll_number << endl;
}

class Exam : public Student
{
protected:
    float maths;
    float physics;

public:
    void set_marks(float, float);
    void get_marks(void);
};

void Exam ::set_marks(float m1, float m2)
{
    this->maths = m1;
    this->physics = m2;
}

void Exam ::get_marks()
{
    cout << "The marks obtained in maths are: " << this->maths << endl;
    cout << "The marks obtained in physics are: " << this->physics << endl;
}

class Result : public Exam
{
    float percentage;

public:
    void display_results()
    {
        get_roll_number();
        get_marks();
        cout << "Roll number: " << this->roll_number << " Result: " << (this->maths + this->physics) / 2 << "%" << endl;
    }
};

int main()
{
    Result harry;
    harry.set_roll_number(66);
    harry.set_marks(94.0, 90.0);
    harry.display_results();
    return 0;
}