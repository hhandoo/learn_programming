#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        // Map to store the frequency of prefix sums modulo k
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // Initialize to handle the case when a prefix sum itself is divisible by k
        int currentSum = 0;
        int count = 0;

        for (int num : nums)
        {
            currentSum += num;
            int mod = currentSum % k;

            // Normalize mod to always be positive
            if (mod < 0)
            {
                mod += k;
            }

            // If mod has been seen before, there are subarrays whose sum is divisible by k
            if (prefixCount.find(mod) != prefixCount.end())
            {
                count += prefixCount[mod];
            }

            // Update the frequency of the current mod value
            prefixCount[mod]++;
        }

        return count;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<int> nums1 = {4, 5, 0, -2, -3, 1};
    int k1 = 5;
    cout << "Example 1 Output: " << solution.subarraysDivByK(nums1, k1) << endl; // Expected Output: 7

    // Example 2
    vector<int> nums2 = {5};
    int k2 = 9;
    cout << "Example 2 Output: " << solution.subarraysDivByK(nums2, k2) << endl; // Expected Output: 0

    return 0;
}
