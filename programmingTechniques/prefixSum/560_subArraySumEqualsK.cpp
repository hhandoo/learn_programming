#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countSubarrayEqualsk(vector<int> &nums, int k)
{
    int cumsum = 0, count = 0;
    unordered_map<int, int> sumcount;
    sumcount[0] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        cumsum += nums[i];

        if (sumcount.find(cumsum - k) != sumcount.end())
        {
            count += sumcount[cumsum - k];
        }

        sumcount[cumsum]++;
    }

    return count;
}

int main()
{
    vector<int> nums = {1,2,3}; // Example array
    int k = 3;                    // Target sum

    int result = countSubarrayEqualsk(nums, k);

    cout << "Number of subarrays whose sum equals " << k << " is: " << result << endl;

    return 0;
}