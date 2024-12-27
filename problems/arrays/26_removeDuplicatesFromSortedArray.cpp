#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int j = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[j] = nums[i];
            j++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }

        cout << endl;
    }
    return j;
}

int main()
{
    vector<int> vec = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    removeDuplicates(vec);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

    cout << endl;

    return 0;
}