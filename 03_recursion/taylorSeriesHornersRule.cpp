#include <iostream>

using namespace std;

// recursive approach
double fun1(double x, double n)
{
    static double s = 1;

    if (n == 0)
    {
        return s;
    }
    else
    {
        s = 1 + (x / n) * s;
        return fun1(x, n - 1);
    }
}

// efficient approach
double fun2(double x, double n)
{
    static double s = 1;
    double den = n;
    for (int i = n; i > 0; i--)
    {
        s = 1 + x / den * s;
        den--;
    }

    return s;
}

int main()
{
    double res;

    res = fun1(2, 10);
    cout << res << endl;
    res = fun2(3, 20);
    cout << res << endl;
    return 0;
}