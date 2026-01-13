//missing-number logic using sum method
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> arr(100);
    int n,missing;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the array elements from 0 to n: ";
    int exp=0,act=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        act+=arr[i];
    }
    exp= (n*(n+1))/2;
    missing = exp-act;
    cout<<"Missing number: "<<missing;

}