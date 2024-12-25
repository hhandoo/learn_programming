#include <iostream>

using namespace std;

int fun1(int m, int n)
{
    if (n == -1)
    {
        return 0;
    }
    else if (n == 0)
    {
        return 1;
    }
    else
    {
        return fun1(m, n - 1) * m;
    }
}

int fun2(int m, int n)
{
    if (n == -1)
    {
        return 0;
    }
    else if (n == 0)
    {
        return 1;
    }
    else
    {
        if (n % 2 == 0)
        {
            return fun2(m * m, n / 2);
        }
        else
        {
            return m * fun2(m * m, (n - 1) / 2);
        }
    }
}

int main()
{
    int x;
    x = fun1(2, 3);
    cout << x << endl;
    x = fun2(2, 3);
    cout << x << endl;
    return 0;
}

// efficient approach
// 2^9 = 2 * (2*2)^4
// m^n = m * (m*m)^(n-1)/2; when n is odd
// 2^8 = (2^2)^4
// m^n = (m*m)^n/2; when n is even