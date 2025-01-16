#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSubarraySum(vector<int> &arr)
{
    int max_sum = INT_MIN;
    int current_sum = 0;

    for (int num : arr)
    {
        current_sum += num;
        if (current_sum > max_sum)
        {
            max_sum = current_sum;
        }
        if (current_sum < 0)
        {
            current_sum = 0;
        }
    }

    return max_sum;
}

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int res = maxSubarraySum(arr);

    cout << res << endl;
    return 0;
}