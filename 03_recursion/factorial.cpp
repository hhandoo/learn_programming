#include <iostream>

using namespace std;

int fun(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return fun(n - 1) * n;
    }
}

int main()
{
    int n = 0;
    n = fun(5);
    cout << n << endl;
    return 0;
}

// n! = 1*2*3*4*5*....*n
// 5! = 1*2*3*4*5
// fact(n) = 1*2*3*4*.......(n-1)*n
// fact(n) = fact(n-1)*n

// fact(n) = { 0;                    n=1
//           { factn(n-1)*n;         n>0