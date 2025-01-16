#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int l = i + 1, r = n - 1;

        while (l < r)
        {
            int threeSum = nums[l] + nums[r] + nums[i];

            if (threeSum == 0)
            {
                result.push_back({nums[i], nums[l], nums[r]});

                l++;

                while (nums[l] == nums[l - 1] && l < r)
                {

                    l++;
                }
            }
            else if (threeSum > 0)
            {
                r--;
            }
            else if (threeSum < 0)
            {
                l++;
            }
        }
    }

    return result;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        vector<int> arr2 = res[i];
        for (int j = 0; j < arr2.size(); j++)
        {
            cout << arr2[j] << " ";
        }
        cout << "]";
        cout << endl;
    }
    return 0;
}