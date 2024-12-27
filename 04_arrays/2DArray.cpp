#include <iostream>

using namespace std;

int main()
{
    // dec and init 2d array
    // declaration of ‘A’ as multidimensional array must have bounds
    // for all dimensions except the first, so A[][] is not valid
    int A[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    // declaring array in heap

    int *arr[3];

    arr[0] = (int *)malloc(3 * sizeof(int)); // new int[3]
    arr[1] = (int *)malloc(3 * sizeof(int));
    arr[2] = new int[3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // declare a 2d pointer only in stack, no array

    int **arr1;

    arr1 = new int *[3];
    arr1 = (int **)malloc(3 * sizeof(int *));
    arr1[0] = (int *)malloc(3 * sizeof(int));
    arr1[1] = (int *)malloc(3 * sizeof(int));
    arr1[2] = (int *)malloc(3 * sizeof(int));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}