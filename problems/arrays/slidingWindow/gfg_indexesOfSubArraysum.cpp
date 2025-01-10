#include <iostream>
#include <vector>
using namespace std;

vector<int> bruteForceWithSlidingWindow(vector<int> &arr, int target)
{
    int p1 = 0, p2 = 0, sum = arr[0];

    while (p2 < arr.size())
    {
        cout << arr[p1] << arr[p2] << sum << endl;
        if (sum > target)
        {
            sum -= arr[p1];
            p1++;
        }
        else if (sum < target)
        {
            p2++;
            sum += arr[p2]; // can check if p2 crosses size
        }
        else
        {
            return {p1 + 1, p2 + 1};
        }
    }

    return {-1, -1};
}

vector<int> slidingWindow(vector<int> &arr, int target)
{
    int j = 0;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum = sum + arr[i];

        while (sum > target && j < i)
        {
            sum = sum - arr[j];
            j++;
        }
        if (sum == target)
        {
            return {j + 1, i + 1};
        }
    }
    return {-1};
}
int main()
{
    vector<int> arr = {1, 2, 3, 7, 5};
    int target = 12;
    vector<int> res;

    res = slidingWindow(arr, target);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    cout << endl;
}
