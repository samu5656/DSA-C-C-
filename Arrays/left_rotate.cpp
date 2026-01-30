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
    int temp=arr[0];
    for(int i=1;i<n;i++)
    {
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    cout<<"\nLeft rotated array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}