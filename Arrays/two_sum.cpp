#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    bool a;
    cout << "Enter number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << "th element: ";
        cin >> arr[i];
    }
    int target;
    cout<<"Enter target number: ";
    cin>>target;
    sort(arr.begin(),arr.end());
    int low=0;
    int high=n-1;
    while(low<high)
    {
        int sum=arr[low]+arr[high];
        if(sum==target)
        {
            a=true;
            break;
        }
        else if(sum<target)
        {
            low++;
        }
        else{
            high--;
        }
    }
    if(a)
    {
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

}
