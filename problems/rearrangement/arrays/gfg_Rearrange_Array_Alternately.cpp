#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rearrangeArray(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    int n = arr.size();
    int max_elem = arr[n - 1] + 1; // A number greater than the maximum element
    int start = 0, end = n - 1;


    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] += (arr[end] % max_elem) * max_elem;
            end--;
        }
        else
        {
            arr[i] += (arr[start] % max_elem) * max_elem;
            start++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] /= max_elem;
    }
}

int main()
{
    // Example input
    vector<int> arr = {890, 289, 483, 519, 550, 447, 946, 957, 92, 783};

    rearrangeArray(arr);

    // Print the rearranged array
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}