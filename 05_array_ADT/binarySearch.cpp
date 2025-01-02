#include <iostream>

using namespace std;

int searchIndexBinaryRec(int *myarr, int low, int high, int elem)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;

        if (myarr[mid] == elem)
        {
            return mid;
        }
        else if (elem > myarr[mid])
        {
            return searchIndexBinaryRec(myarr, mid + 1, high, elem);
        }
        else if (elem < myarr[mid])
        {
            return searchIndexBinaryRec(myarr, low, mid - 1, elem);
        }
    }
    return -1;
}

int searchIndexBinaryIter(int *myarr, int elem, int size)
{
    int low = 0, high = size, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (myarr[mid] == elem)
        {
            return mid;
        }

        else if (elem > myarr[mid])
        {
            low = mid + 1;
        }
        else if (elem < myarr[mid])
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {4, 8, 10, 15, 18, 21, 24, 27, 29, 33, 37, 39, 41, 43};

    // input array has to be sorted

    int index, size;

    size = sizeof(arr) / sizeof(arr[0]);
    index = searchIndexBinaryIter(arr, 4, size);
    cout << index << endl;

    index = searchIndexBinaryRec(arr, 0, size - 1, 4122);
    cout << index << endl;
    return 0;
}