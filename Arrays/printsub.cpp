// Extended version of kadanes's problem(finding maximum sub and printing array elements).
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
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            flag = false;
            break;
        }
    }
    if (!flag)
    {
        long long maxsum = LLONG_MIN;
        int currsum = 0;
        int start = 0;
        int end = 0;
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            currsum += arr[i];
            if (currsum > maxsum)
            {
                maxsum = currsum;
                start = temp;
                end = i;
            }
            if (currsum < 0)
            {
                currsum = 0;
                temp = i + 1;
            }
        }
        cout << "Maximum Sum: " << maxsum << endl;
        cout << "Subarray: ";

        for (int i = start; i <= end; i++)
            cout << arr[i] << " ";
    }
    else
    {
        long long maxi = LLONG_MIN;
        for (int i = 0; i < n; i++)
        {
            if (maxi < arr[i])
            {
                maxi = arr[i];
            }
        }
        cout << "\nMaximum Sum" << maxi;
        cout << "\nSubarray: " << maxi;
    }

    return 0;
}