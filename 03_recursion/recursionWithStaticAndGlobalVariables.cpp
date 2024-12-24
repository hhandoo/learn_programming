#include <iostream>

using namespace std;

int inc1 = 0;

int fun1(int n)
{
    if (n > 0)
    {
        inc1++;
        cout << "n: "<< n << " inc1: "<<inc1<<" ";
        return fun1(n - 1) + inc1;
    }
    return 0;
}

int fun2(int n)
{
    static int inc2 = 0;
    if (n > 0)
    {
        inc2++;
        cout << "n: "<< n << " inc1: "<<inc2<<" ";
        return fun2(n - 1) + inc2;
    }
    return 0;
}

// fun2(5) = 25

// fun2(4) + _5_  inc1 = 1; 20 + 5 = 25

// fun2(3) + _5_  inc1 = 2; 15 + 5 = 20

// fun2(2) + _5_  inc1 = 3; 10 + 5 = 15

// fun2(1) + _5_  inc1 = 4;  5 + 5 = 10


// fun2(0) + _5_  inc1 = 5 so 0 + 5 = 5

// 0


int main()
{
    // with global variable
    int opt;
    opt = fun1(5);
    cout << opt << endl;
    // with static variable
    opt = fun2(5);
    cout << opt << endl;
    return 0;
}