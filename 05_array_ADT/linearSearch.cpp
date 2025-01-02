#include <iostream>

using namespace std;

int searchIndex(int *myarr, int elem, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (myarr[i] == elem)
        {
            return i;
        }
    }

    return -1;
}

int searchIndexTransposition(int *myarr, int elem, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (myarr[i] == elem)
        {
            if (i != 0)
            {
                int a = myarr[i], b = myarr[i - 1];
                myarr[i - 1] = a;
                myarr[i] = b;
            }
            return i;
        }
    }

    return -1;
}


int searchIndexMoveToHead(int *myarr, int elem, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (myarr[i] == elem)
        {
            if (i != 0)
            {
                int a = myarr[i], b = myarr[0];
                myarr[0] = a;
                myarr[i] = b;
            }
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {8, 9, 4, 7, 6, 3, 10, 5, 14, 2};
    
    int index, size;

    size = sizeof(arr) / sizeof(arr[0]);
    index = searchIndex(arr, 5, size);
    cout << index << endl;
    index = searchIndexTransposition(arr, 5, size);
    cout << index << endl;
    index = searchIndexTransposition(arr, 5, size);
    cout << index << endl;
    index = searchIndexMoveToHead(arr, 5, size);
    cout << index << endl;
    index = searchIndexMoveToHead(arr, 5, size);
    cout << index << endl;
    return 0;
}