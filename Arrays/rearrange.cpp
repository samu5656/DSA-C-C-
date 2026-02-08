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
    vector<int>res(n);
    int pos_index=0,neg_index=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            res[pos_index]=arr[i];
            pos_index+=2;
        }
        else{
            res[neg_index]=arr[i];
            neg_index+=2;
        }
    }
    cout<<"Resultant Array: ";
    for(int i=0;i<n;i++)
    {
        cout<<res[i]<<" ";
    }
}