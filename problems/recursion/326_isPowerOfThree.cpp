#include<iostream>

using namespace std;

bool check(int n)
{
    if(n==1) return true;
    if(n<=0 || n%3 != 0) return false;
    return check(n/3);
}

int main()
{
    int in = 28;
    cout << check(in) << endl;
}