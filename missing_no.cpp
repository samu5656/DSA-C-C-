//finding missing element in given range(non-optimal solution)
//Time Complexity: O(n log n)
//Space Complexity: O(1) extra

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> arr(100);
    int n;
    int a=0;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.begin()+n);
    cout<<"Missing number: ";
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=arr[i-1]+1)
        {
            a++;
            cout<<arr[i-1]+1;
            break;
        }
    }
    if(a==0&&arr[0]!=0)
    {
        a++;
        cout<<arr[0]-1;
    }
    if(a==0)
    {
        cout<<arr[n-1]+1;
    }



}