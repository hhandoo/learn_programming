#include <iostream>

using namespace std;

int fun(int n)
{
    if (n > 100)
    {
        return n - 10;
    }
    else
    {
        return fun(fun(n + 11));
    }
}

int main()
{
    int opt;
    opt = fun(95);
    cout << opt << endl;
    return 0;
}