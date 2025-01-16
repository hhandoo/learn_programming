#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int usingHashmap(vector<int> &nums)
{
    // unordered_map<int, bool> mymap;

    // int n = nums.size() + 1;

    // for (int x : nums)
    // {
    //     mymap[x] = true;
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     if (mymap.find(i) == mymap.end())
    //     {
    //         return i;
    //     }
    // }

    // return -1;

    int n = nums.size();
    vector<int> v(n + 1, -1);

    for (int i = 0; i < nums.size(); i++)
    {
        v[nums[i]] = nums[i];
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == -1)
            return i;
    }
    return 0;
}

int usingXOR(vector<int> &arr)
{
    int n = arr.size() + 1;
    int xor_all = 0;
    int xor_arr = 0;

    // XOR all numbers from 1 to n
    for (int i = 1; i <= n; i++)
    {
        xor_all ^= i;
    }

    // XOR all numbers from 1 to n
    for (int num : arr)
    {
        xor_arr ^= num;
    }

    return xor_all ^ xor_arr;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 5};
    vector<int> arr2 = {8, 2, 4, 5, 3, 7, 1};
    vector<int> arr3 = {1};

    cout << usingHashmap(arr1) << endl;
    cout << usingXOR(arr1) << endl;

    return 0;
}