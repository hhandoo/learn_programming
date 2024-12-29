#include <iostream>
#include <vector>
using namespace std;

vector<int> generatePrefixArray(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> prefix(n);

    prefix[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    return prefix;
}

int computeSum(int L, int R, vector<int> &prefix)
{
    if (L == 0)
    {
        return prefix[R];
    }
    else
    {
        return prefix[R] - prefix[L - 1];
    }
}

int main()
{
    vector<int> inp = {2, 4, 6, 8, 10};
    vector<int> opPrefix;
    opPrefix = generatePrefixArray(inp);

    for (int i = 0; i < opPrefix.size(); i++)
    {
        cout << opPrefix[i] << " ";
    }
    cout << endl;

    int sum;

    sum = computeSum(1, 3, opPrefix);

    cout << sum << endl;

    return 0;
}