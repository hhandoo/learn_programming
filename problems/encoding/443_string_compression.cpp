#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char> &chars)
{
    int n = chars.size();

    int read = 0, write = 0;

    while (read < n)
    {
        char currentChar = chars[read];
        int count = 0;

        while (read < n && chars[read] == currentChar)
        {
            read++;
            count++;
        }

        chars[write] = currentChar;
        write++;

        if (count > 1) 
        // because if count is 10 then 
        // {'a','1','0'} and if input is {'a','b'} then
        // it won't be {'a', '1', 'b','1'}
        {
            for (char c : to_string(count))
            {
                chars[write++] = c;
            }
        }
    }

    return write;
}

int main()
{
    vector<char> chars = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'C', 'C', 'C', 'D', 'D', 'D', 'D', 'D', 'D'};
    int newLength = compress(chars);

    cout << "Compressed Length: " << newLength << endl;
    cout << "Compressed Characters: ";
    for (int i = 0; i < newLength; ++i)
    {
        cout << chars[i];
    }
    cout << endl;

    return 0;
}
