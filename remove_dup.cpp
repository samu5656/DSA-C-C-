#include <iostream>
using namespace std;
int main()
{
    int n,count=0;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];
    cout << "Enter Array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int dup = arr[i];
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if(dup==arr[j])
                {
                    count++;
                    n--;   
                    for(int k=j;k<n;k++)
                    {
                        arr[k]=arr[k+1];
                    }
                }
            }
        }
    }
    cout<<"Array after removing duplicates: ";
    for(int i=0;i<n;i++)
    {
        cout<<"\n"<<arr[i];
    }
    cout<<"\nThe number of duplicate elements: "<<count;
}