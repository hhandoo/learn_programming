#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string alphabeticallySmallestString(string &str)
{
    int n = str.size();
    vector<string> candidates = {str};

    // generate candidates by reversing prefixes
    for (int i = 0; i < n; i++)
    {
        string reversed_prefix = str.substr(0, i);
        reverse(reversed_prefix.begin(), reversed_prefix.end());
        candidates.push_back(reversed_prefix + str.substr(i));
    }

    // generate candidates by reversing suffixes
    for (int i = n - 1; i > -1; i--)
    {
        string reversed_suffix = str.substr(i);
        reverse(reversed_suffix.begin(), reversed_suffix.end());
        candidates.push_back(str.substr(0, i) + reversed_suffix);
    }

    return *min_element(candidates.begin(), candidates.end());
}

int main()
{
    string word = "dbaca";
    string result = alphabeticallySmallestString(word);
    cout << result << endl;
    return 0;
}