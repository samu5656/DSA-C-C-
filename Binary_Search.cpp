// Problem: Binary Search
// Source: GeeksforGeeks
// Approach: Divide and Conquer
#include <iostream>
using namespace std;

int binary(int key,int a[],int n)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid= low+(high-low)/2;
        if(a[mid]==key)
        {
            return mid;
        }
        if(a[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}
int main() {
    // Write C++ code here
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element "<<i<<":";
        cin>>arr[i];
    }
    int key;
    cout<<"Enter element to search: ";
    cin>>key;
    int s=binary(key,arr,n);
    if(s!=-1)
    {
        cout<<"Element found at index:"<<s;
    }
    else
    {
        cout<<"Element not found";
    }
    return 0;
}