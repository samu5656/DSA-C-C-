#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    int left = 0, max_len = 0;
    unordered_set<char> chars;
    for (int right = 0; right < str.size(); right++)
    {
        while (chars.count(str[right]))
        {
            chars.erase(str[left]);
            left++;
        }
        chars.insert(str[right]);
        max_len = max(max_len, right - left + 1);
    }
    cout << "Length of longest substring : " << max_len;
}