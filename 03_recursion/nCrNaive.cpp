#include <iostream>

using namespace std;

int fact(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return fact(n - 1) * n;
    }
}

int nCr(int n, int r)
{
    int num = fact(n);
    int r1 = fact(r);
    int den = r1 * fact(n - r);

    return num / den;
}

int main()
{
    int res;

    res = nCr(5, 2);

    cout << res << endl;

    return 0;
}