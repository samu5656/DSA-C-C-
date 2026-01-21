#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements one by one: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int largest,sec_largest=0;
    largest= arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>largest)
        {
            sec_largest=largest;
            largest= arr[i];
        }
        else if(arr[i]<largest && arr[i]>sec_largest)
        {
            sec_largest = arr[i];
        }
    }
    cout<<"Second largest: "<<sec_largest;
    return 0;
}