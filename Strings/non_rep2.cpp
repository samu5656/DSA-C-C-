//Option solution for finding first non-repeating string
#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
using namespace std;
int main()
{
    vector<string> arr = {"apple", "banana", "apple", "orange", "banana"};
    string res = "NONE";
    unordered_map<string,int> freq;
    for(int i=0;i<arr.size();i++)
    {
        freq[arr[i]]++;
    }
    for(int i=0;i<arr.size();i++)
    {
        if(freq[arr[i]]==1)
        {
            res=arr[i];
        }
    }
    cout<<res;
}