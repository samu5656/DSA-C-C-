#include <iostream>
#include <string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    string str;
    cout<<"Enter a string:  ";
    getline(cin,str);
    vector<int>freq(256,0);
    for(char c : str)
    {
        freq[c]++;
    }
    for(int i=0;i<str.size();i++)
    {
        if(freq[str[i]]==1)
        {
            cout<<i;
            return 0;
        }
    }
    cout<< -1;
    return 0;
}