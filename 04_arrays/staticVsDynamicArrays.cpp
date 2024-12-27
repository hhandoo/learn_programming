#include <iostream>

using namespace std;

int main()
{
    // declaring static array
    // resides as an activation record in the stack  frame of the main function in the stack memory.
    // these arrays are called static as they are created during compile time.
    int A[5] = {1, 2, 3, 4, 5};
    // declaring an array in heap
    // Array declarations in the heap are called dynamic arrays because they are created and managed at runtime,
    // allowing for greater flexibility in terms of size and memory management compared to arrays declared in the stack or statically.
    int *arr;
    arr = (int *)malloc(5 * sizeof(int));
    arr = new int[5];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // how to increase size of dynamic array ?

    // step 1: Create an array in heap of required size.
    // step 2: transfer all elements of exising array in this one.
    // step 3: delete p
    // step 4: attach pointer of existing array to new one.
    // step 5: make new array pointer null

    int *arr2;
    arr2 = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        arr2[i] = arr[i];
    }
    free(arr);
    arr = arr2;
    arr2 = NULL;
    for (int i = 0; i < 5; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}