#include <iostream>
using namespace std;

template <class T>
class vector
{
public:
    T *arr; // pointer to array
    int size;
    vector(int m)
    {
        size = m;
        arr = new T[size];
    }

    T dotProduct(vector &v)
    {
        T d = 0;
        for (int i = 0; i < size; i++)
        {
            d += this->arr[i] * v.arr[i];
        }
        return d;
    }
};

int main()
{
    vector<int> v1(3);
    v1.arr[0] = 1;
    v1.arr[1] = 2;
    v1.arr[2] = 3;

    vector<int> v2(3);
    v2.arr[0] = 3;
    v2.arr[1] = 2;
    v2.arr[2] = 1;

    int r1 = v1.dotProduct(v2);
    cout << r1 << endl;

    vector<float> v1f(3);
    v1f.arr[0] = 1.0;
    v1f.arr[1] = 2.1;
    v1f.arr[2] = 3.7;

    vector<float> v2f(3);
    v2f.arr[0] = 0.9;
    v2f.arr[1] = 2.1;
    v2f.arr[2] = 0.1;

    float r2 = v1f.dotProduct(v2f);
    cout << r2 << endl;
    return 0;
}