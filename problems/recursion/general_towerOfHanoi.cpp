#include <iostream>

using namespace std;

void TOH(int n, int A, int B, int C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B); // move from A to C using B as aux
        cout << "Move disk from " << A << " to " << C << endl;
        TOH(n - 1, B, A, C); // move from B to A using C as aux
    }
}

int main()
{
    int n = 3;
    TOH(16, 1, 2, 3);
    return 0;
}