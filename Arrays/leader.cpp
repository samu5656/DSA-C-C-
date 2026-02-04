#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << "th element: ";
        cin >> arr[i];
    }
    vector<int>leader;
    int maxi=arr[n-1];
    leader.push_back(maxi);
    for(int i=n-2;i>0;i--)
    {
        if(arr[i]>maxi)
        {
            leader.push_back(arr[i]);
            maxi=arr[i];
        }
    }
    reverse(leader.begin(),leader.end());
    cout<<"\nLeader elements: ";
    for(int i=0;i<leader.size();i++)
    {
        cout<<leader[i]<<" ";
    }
}   