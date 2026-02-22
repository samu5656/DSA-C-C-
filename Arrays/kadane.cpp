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
    long long maxi = LLONG_MIN;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxi = max(maxi, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << "The maximum subarray sum is: " << maxi;
}
