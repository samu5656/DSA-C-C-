//To find maximum consecutive ones in an array
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int count=0;
    int maxcount=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            count++;
        }
        else 
        {
            count=0;
        }
        maxcount=max(count,maxcount);
    }
    cout<<"\nMaximum consecutive ones: "<<maxcount;
}