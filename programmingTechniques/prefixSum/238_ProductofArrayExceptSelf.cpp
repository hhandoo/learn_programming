#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int prefix = 1, postfix = 1, n = nums.size();

    vector<int> answer(n, 1);

    // prefix
    for (int i = 0; i < n; i++)
    {
        answer[i] = prefix;
        prefix *= nums[i];

    }

    // postfix
    for (int i = n - 1; i > -1; i--)
    {

        answer[i] *= postfix;
        postfix *= nums[i];
    }


    return answer;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(nums);

    cout << "Result: [";
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i != result.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}