#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool checkSubarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> remcount;
    remcount[0] = -1;
    int cumsum = 0, count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        cumsum += nums[i];

        if (cumsum % k != 0)
        {
            cumsum = cumsum % k;
        }
        if (remcount.find(cumsum) != remcount.end())
        {

            if (i - remcount[cumsum] > 1)
            {
                return true;
            }
        }
        else
        {
            remcount[cumsum] = i;
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;

    if (checkSubarraySum(nums, k))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}