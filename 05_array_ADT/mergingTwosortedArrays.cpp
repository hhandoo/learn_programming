#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeTwosortedArrays(vector<int> &a, vector<int> &b)
{
    int i = 0, j = 0;
    vector<int> result;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            result.push_back(a[i]);
            i++;
        }
        else
        {
            result.push_back(b[j]);
            j++;
        }
    }

    while (i < a.size())
    {
        result.push_back(a[i]);
        i++;
    }

    while (j < b.size())
    {
        result.push_back(b[j]);
        j++;
    }

    return result;
}

int main()
{
    vector<int> arr1 = {1, 5, 7, 9, 10};
    vector<int> arr2 = {2, 3, 4};

    vector<int> result;

    result = mergeTwosortedArrays(arr1, arr2);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;
}