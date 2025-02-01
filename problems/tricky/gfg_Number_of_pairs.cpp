#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getIndex(vector<int> &arr, int elm)
{
    int l = 0, r = arr.size() - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (elm == arr[mid])
        {
            return mid;
        }
        else if (elm > arr[mid])
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {4, 8, 10, 15, 18, 21, 24, 27, 29, 33, 37, 39, 41, 43};

    // input array has to be sorted

    int index, size;

    index = getIndex(arr, 21);
    cout << index << endl;

    return 0;
}