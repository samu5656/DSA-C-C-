// To return first non repeating string
//time complexity: O(n²)
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<string> arr = {"apple", "banana", "apple", "orange", "banana"};
    string res = "NONE";
    for (int i = 0; i < arr.size(); i++)
    {
        bool dup = true;

        for (int j = 0; j < arr.size(); j++)
        {
            if (i == j)
                continue;

            if (arr[i] == arr[j])
            {
                dup = false;
                break;
            }
        }
        if (dup)
        {
            res = arr[i];
            break;
        }
    }
    cout << res;
}