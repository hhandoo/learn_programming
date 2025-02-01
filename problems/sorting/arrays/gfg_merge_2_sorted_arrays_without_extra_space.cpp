#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergeArrays(vector<int> &a, vector<int> &b)
{
    int sa = a.size(), sb = b.size();
    int i = sa - 1;
    int j = 0;

    while (i >= 0 && j < sb)
    {
        if (a[i] > b[j])
        {
            swap(a[i], b[j]);
        }
        i--;
        j++;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

int main()
{
    vector<int> a = {2, 4, 7, 10};
    vector<int> b = {2, 3};

    mergeArrays(a, b);

    cout << "Array a: ";
    for (int x : a)
        cout << x << " ";
    cout << "\n";

    cout << "Array b: ";
    for (int x : b)
        cout << x << " ";
    cout << "\n";
    return 0;
}