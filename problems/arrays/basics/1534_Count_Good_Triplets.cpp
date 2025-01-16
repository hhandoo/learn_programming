

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countGoodTriplets(vector<int> &arr, int a, int b, int c)
{
    int res = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                {
                    res++;
                }
            }
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {3, 0, 1, 1, 9, 7};
    int res = countGoodTriplets(arr, 7, 2, 3);
    cout << res << endl;
    return 0;
}