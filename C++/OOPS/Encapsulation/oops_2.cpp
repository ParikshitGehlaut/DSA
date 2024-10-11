#include <iostream>
using namespace std;

class Binary
{
    string s;

public:
    void read(void);
    void chk_binary(void);
};

void Binary ::read(void)
{
    cout << "Enter a Binary number." << endl;
    cin >> s;
}

void Binary ::chk_binary(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Incorrect Binary Format" << endl;
            exit(0);
        }
    }
}

int main()
{
    Binary b;
    b.read();
    b.chk_binary();
    return 0;
}