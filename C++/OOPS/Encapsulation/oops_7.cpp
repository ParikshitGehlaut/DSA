#include <iostream>
using namespace std;

class BankDeposit
{
    int p;
    int t; // in years
    float r;
    float A; // total amount

public:
    BankDeposit() {};
    BankDeposit(int p, int t, float r);
    BankDeposit(int p, int t, int r);
    void show(void);
};

BankDeposit ::BankDeposit(int p, int t, float r)
{
    this->p = p;
    this->t = t;
    this->r = r;
    A = p;
    for (int i = 0; i < t; i++)
    {
        A *= (1 + r);
    }
}
BankDeposit ::BankDeposit(int p, int t, int r)
{
    this->p = p;
    this->t = t;
    this->r = float(r) / 100;
    A = p;
    for (int i = 0; i < t; i++)
    {
        A *= (1 + this->r);
    }
}

void BankDeposit ::show()
{
    cout << "Amount invested " << p << endl
         << "market value after " << t << " years is " << A << endl;
}

int main()
{
    int p = 10000;
    int t = 30;
    float r = 0.18;
    BankDeposit b1(p, t, r);
    b1.show();
    return 0;
}