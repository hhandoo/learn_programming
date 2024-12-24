#include <iostream>

using namespace std;

void countOneToN(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        countOneToN(n - 1);
    }
}

void countNtoOne(int n)
{
    if (n > 0)
    {
        countNtoOne(n - 1);
        cout << n << " ";
    }
}

int main()
{
    countOneToN(10);
    cout << "" << endl;
    countNtoOne(10);
    cout << "" << endl;
    return 0;
}