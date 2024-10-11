#include <iostream>
#include <cmath> 
using namespace std;

class SimpleCalculator {
public:
    float a;
    float b;

    void input() {
        cout << "Enter two numbers:\n";
        cin >> a >> b;
    }

    void addition() {
        cout << "+ : " << a + b << endl;
    }

    void subtraction() {
        cout << "- : " << a - b << endl;
    }

    void multiplication() {
        cout << "* : " << a * b << endl;
    }

    void division() {
        if (b != 0)
            cout << "/ : " << a / b << endl;
        else
            cout << "Division by zero is not allowed!" << endl;
    }
};

class ScientificCalculator {
public:
    float a;
    float b;

    void SqAdd() {
        cout << "a^2 + b^2 : " << pow(a, 2) + pow(b, 2) << endl;
    }

    void SqSub() {
        cout << "a^2 - b^2 : " << pow(a, 2) - pow(b, 2) << endl;
    }

    void WholeSqAdd() {
        cout << "(a + b)^2 : " << pow(a + b, 2) << endl;
    }

    void WholeSqSub() {
        cout << "(a - b)^2 : " << pow(a - b, 2) << endl;
    }
};

class HybridCalculator : public SimpleCalculator, public ScientificCalculator {
public:
    void input() {
        SimpleCalculator::input();
        ScientificCalculator::a = SimpleCalculator::a; 
        ScientificCalculator::b = SimpleCalculator::b; 
    }

    void Display() {
        addition();
        subtraction();
        multiplication();
        division();
        SqAdd();
        SqSub();
        WholeSqAdd();
        WholeSqSub();
    }
};

int main() {
    HybridCalculator cal;
    cal.input(); 
    cal.Display(); 
    return 0;
}
