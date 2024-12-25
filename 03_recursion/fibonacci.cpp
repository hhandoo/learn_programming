#include <iostream>

using namespace std;

int fibIter(int n)
{
    int t0 = 0, t1 = 1, res;
    for (int i = 2; i <= n; i++)
    {
        res = t0 + t1;
        t0 = t1;
        t1 = res;
    }
    return res;
}

int fibrec(int n)
{
    // too many recursive calls
    // not optimized
    if (n <= 1)
    {
        return n;
    }
    return fibrec(n - 2) + fibrec(n - 1);
}

int F[10] = {
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1};

int fibRecWMemoization(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
        {
            F[n - 2] = fibRecWMemoization(n - 2);
        }
        if (F[n - 1] == -1)
        {
            F[n - 1] = fibRecWMemoization(n - 1);
        }
        return F[n - 2] + F[n - 1];
    }
}

int main()
{
    int res;
    res = fibIter(6);
    cout << res << endl;
    res = fibrec(6);
    cout << res << endl;
    res = fibRecWMemoization(6);
    cout << res << endl;
}
