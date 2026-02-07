#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k=15;
    int n=arr.size();
    int max_len=0,sum=arr[0];
    int left=0,right=0;
    while(right<n)
    {
        while(left<=right && sum>k)
        {
            sum-=arr[left];
            left++;
        }
        if(sum==k)
        {
            max_len=max(max_len,right-left+1);
        }
        right++;
        if(right<n)
        {
            sum+=arr[right];
        }
    }
    cout<<"Length of longest subarray with sum "<<k<<" is: "<<max_len;
}