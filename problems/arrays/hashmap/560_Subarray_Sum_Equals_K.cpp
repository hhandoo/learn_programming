#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ref : https://www.youtube.com/watch?v=xvNwoz-ufXA&ab_channel=takeUforward
int subarraySumBruteforce(vector<int> &nums, int k)
{
    int sum, cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum == k)
            {
                cnt++;
            }
        }
    }

    return cnt;
}

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mymap;
    mymap[0] = 1;
    int presum = 0, cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        presum += nums[i];
        int remove = presum - k;
        cnt += mymap[remove];

        mymap[presum] += 1;
    }

    return cnt;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int out = subarraySumBruteforce(arr, 3);
    cout << out << endl;
}