//Find the number that appears once, and the other numbers twice


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
    unordered_map<int,int>freq;
    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(freq[arr[i]]==1)
        {
            cout<<arr[i]<<" ";
        }
    }
    //using xor method:
    int xorr=0;
    for(int i=0;i<n;i++)
    {
        xorr=xorr^arr[i];
    }
    cout<<"\nOutput using XOR method: "<<xorr;
}