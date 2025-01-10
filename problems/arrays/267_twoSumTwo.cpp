#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{

    int i = 0, j = nums.size() - 1;

    while (i <= j)
    {

        if (nums[i] + nums[j] == target)
        {
            return {i + 1, j + 1};
        }
        else if (nums[i] + nums[j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return {};
}
int main()
{
    vector<int> vec = {1, 2, 3, 4};
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