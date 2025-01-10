#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mymap;
    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if (mymap.count(complement))
        {
            return {mymap[complement], i};
        }
        mymap[nums[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> vec = {3, 2, 4};
    vector<int> vec2;
    int target = 6;
    vec2 = twoSum(vec, target);

    for (int i = 0; i < vec2.size(); i++)
    {
        cout << vec2[i] << " ";
    }
    cout << endl;

    return 0;
}