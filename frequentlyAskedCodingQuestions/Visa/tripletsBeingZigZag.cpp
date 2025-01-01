// Given an array of integers `numbers`, your task is to check all the triples of its consecutive elements for being a zigzag. More formally, your task is to construct an array of length `numbers.length - 2` where the \(i^{th}\) element of the output array equals:
// - 1 if the triple `(numbers[i], numbers[i+1], numbers[i+2])` is a zigzag, and
// - 0 otherwise.

// ### Example

// - For `numbers = [1, 2, 1, 3, 4]`, the output should be `solution(numbers) = [1, 1, 0]`.
//   - `(numbers[0], numbers[1], numbers[2]) = (1, 2, 1)` is a zigzag because \(1 < 2 > 1\).
//   - `(numbers[1], numbers[2], numbers[3]) = (2, 1, 3)` is a zigzag because \(2 > 1 < 3\).
//   - `(numbers[2], numbers[3], numbers[4]) = (1, 3, 4)` is not a zigzag because \(1 < 3 < 4\).

// - For `numbers = [1, 2, 3, 4]`, the output should be `solution(numbers) = [0, 0]`.
//   - Since all the elements of `numbers` are increasing, there are no zigzags.

// - For `numbers = [1000000000, 1000000000, 1000000000]`, the output should be `solution(numbers) = [0]`.
//   - Since all the elements of `numbers` are the same, there are no zigzags.

#include <iostream>
#include <vector>

using namespace std;

vector<int> detectTriplets(vector<int> &nums)
{
    vector<int> res;
    for (int i = 1; i <= nums.size() - 2; i++)
    {
        if ((nums[i - 1] < nums[i]) && (nums[i] > nums[i + 1]))
        {
            res.push_back(1);
        }
        else if ((nums[i - 1] > nums[i]) && (nums[i] < nums[i + 1]))
        {
            res.push_back(1);
        }

        else
        {
            res.push_back(0);
        }
    }

    return res;
}

int main()
{
    vector<int> numbers = {1, 2, 1, 3, 4};
    vector<int> res;
    res = detectTriplets(numbers);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}