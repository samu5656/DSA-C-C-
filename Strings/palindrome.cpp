#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    bool val = true;
    cout << "Enter a string: ";
    getline(cin, str);
    int low = 0;
    int high = str.size() - 1;
    while (low < high)
    {
        if (str[low] != str[high])
        {
            val = false;
            break;
        }
        low++;
        high--;
    }
    if (!val)
    {
        cout << "It is not a palindrome";
    }
    else
    {
        cout<<"It is a palindrome";
    }
}