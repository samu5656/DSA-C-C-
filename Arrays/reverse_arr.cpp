//Program to reverse an array
#include<iostream>
using namespace std;
int main()
{
    int arr[100];
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the array elements: \n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int low=0;
    int high=n-1;
    while(low<high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high]=temp;
        low++;
        high--;
    }
    cout<<"Reversed array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}