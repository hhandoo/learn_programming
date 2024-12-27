#include <iostream>

using namespace std;

int main()
{
    // arrays are actually addresses
    // so they can be assigned to pointers
    int A[5];
    A[2] = 14;
    int *p;
    p = A;

    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << " ";
    }

    cout << endl;

    int B[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        cout << B[i] << " ";
    }

    cout << endl;

    int C[5] = {1,7 };

    for (int i = 0; i < 5; i++)
    {
        cout << i[C] << " ";
    }

    cout << endl;


    return 0;
}
