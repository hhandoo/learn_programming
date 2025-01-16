#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bruteForce(vector<int> &nums)
{
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int dig1 = nums[i];
        for (int j = i + 1; j < nums.size(); j++)
        {
            int dig2 = nums[j];
            for (int k = j + 1; k < nums.size(); k++)
            {
                int dig3 = nums[k];

                if (dig1 + dig2 == dig3)
                {
                    res += 1;
                }
                else if (dig2 + dig3 == dig1)
                {
                    res += 1;
                }
                else if (dig3 + dig1 == dig2)
                {
                    res += 1;
                }
            }
        }
    }
    return res;
}

int optimizedApproach(vector<int> &arr)
{
    int count = 0;
    sort(arr.begin(), arr.end());
    int n = arr.size() ;
    for (int i = 0; i < n; i++)
    {
        int left = 0, right = i - 1;
        while (left < right)
        {
            if (arr[left] + arr[right] == arr[i])
            {
                count++;
                left++;
                right--;
            }
            else if (arr[left] + arr[right] < arr[i])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return count;
}
int main()
{
    vector<int> arr = {1, 5, 3, 2};
    int res = optimizedApproach(arr);
    cout << res << endl;
    return 0;
}