#include <iostream>
#include <vector>
#include <string>

using namespace std;

string compressString(const string &s)
{
    if (s.empty())
        return "";

    string result;
    int count = 1;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            count++;
        }
        else
        {
            result += s[i - 1] + to_string(count);
            count = 1;
        }
    }

    result += s.back() + to_string(count);

    return result;
}

int main()
{
    string input = "AAAABBBCCCCCCDDDDDD";
    string compressed = compressString(input);
    cout << "Compressed String: " << compressed << endl;
    return 0;
}