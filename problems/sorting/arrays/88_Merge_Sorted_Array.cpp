#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;     // Pointer for the last valid element in nums1
    int j = n - 1;     // Pointer for the last element in nums2
    int k = m + n - 1; // Pointer for the last position in nums1

    // Step 1: Compare and place larger elements in nums1
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }

    // Step 2: Copy any remaining elements from nums2
    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    merge(nums1, m, nums2, n);

    // Print the merged array
    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}