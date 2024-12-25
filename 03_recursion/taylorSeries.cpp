#include <iostream>

using namespace std;

// naive approach
double fun1(int x, int n)
{
    static double p = 1, f = 1;
    double r;

    if (n == 0)
    {
        return 1;
    }
    else
    {
        r = fun1(x, n - 1);
        p = x * p;
        f = n * f;
        return r + p / f;
    }
}

int main()
{
    double res;
    res = fun1(3, 200);
    cout << res << endl;
    return 0;
}