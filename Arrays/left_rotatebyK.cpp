#include <bits/stdc++.h>
using namespace std;
void helper(vector<int> &a, int left, int right)
{
    int low = left;
    int high = right;
    while (low < high)
    {
        swap(a[low], a[high]);
        low++;
        high--;
    }
}
int main()
{
    int n, k;
    cout << "Enter number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << "th element: ";
        cin >> arr[i];
    }
    cout << "Enter the value of K: ";
    cin >> k;
    k=k%n;
    helper(arr, 0, k-1);
    helper(arr, k, n-1);
    helper(arr, 0, n-1);
    cout << "Left rotated array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}