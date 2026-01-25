#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
    vector<int> nums={11, 7, 1, 13, 21, 3, 7, 3};
    vector<int> subs={11, 3, 7, 1, 7};
    unordered_map<int, int> freq;
    bool res=true;
    for(int i=0;i<nums.size();i++)
    {
        freq[nums[i]]++;
    }
    for(int i=0;i<subs.size();i++)
    {
        if(freq[subs[i]]==0)
        {
            res=false;
        }
        freq[subs[i]]--;
    }
    if(res)
    {
        cout<<"It is a subset";
    }
    else{
        cout<<"It is not a subset";
    }
}