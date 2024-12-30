#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxSubArraySum(vector<int> &nums)
{
    unordered_map<int, int> sumcount;
    vector<int> minusone;

    sumcount[0] = -1;

    int cumsum = 0, maxcount = 0;

    // replace with zeros

    for (int i = 0; i < nums.size(); i++)
    {

        if (nums[i] == 0)
        {
            minusone.push_back(-1);
        }
        else
        {
            minusone.push_back(nums[i]);
        }
    }

    for (int i = 0; i < minusone.size(); i++)
    {

        cumsum += minusone[i];

        if (sumcount.find(cumsum) != sumcount.end())
        {
            // sumcount[maxcount] is the old index
            maxcount = max(maxcount, i - sumcount[cumsum]);
        }
        else
        {
            sumcount[cumsum] = i;
        }
    }

    return maxcount;
}

int main()
{
    vector<int> nums = {0, 0, 1, 0, 1, 1, 0};
    cout << maxSubArraySum(nums) << endl;
    return 0;
}