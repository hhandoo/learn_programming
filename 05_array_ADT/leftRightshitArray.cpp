#include <iostream>
#include <vector>

using namespace std;

int *rightRotate(vector<int> &arr, int n)
{

    int *result = new int[arr.size()];

    if (n > arr.size())
    {
        n = n % arr.size();
    }

    int temp[n];

    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[arr.size() - n + i];
    }

    for (int i = 0; i < n; i++)
    {
        result[i] = temp[i];
    }

    for (int i = n ; i < arr.size(); i++)
    {
        result[i] = arr[i - n];
    }

    return result;
}

int *leftRotate(vector<int> &arr, int n)
{
    // create temp array to store rotate elements.

    if (n > arr.size())
    {
        n = n % arr.size();
    }

    int temp[n];
    int *res = new int[arr.size()];

    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i];
    }
    int ctr1 = 0;

    for (int i = n - 1; i < arr.size(); i++)
    {
        res[ctr1] = arr[i];
        ctr1++;
    }
    int ctr = 0;
    for (int i = arr.size() - n; i < arr.size(); i++)
    {

        res[i] = temp[ctr];
        ctr++;
    }

    return res;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int *result = leftRotate(arr, 14);

    for (int i = 0; i < 10; i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;

    int *result2 = rightRotate(arr, 14);

    for (int i = 0; i < 10; i++)
    {
        cout << result2[i] << " ";
    }

    cout << endl;
}