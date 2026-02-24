#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[100];
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the array elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int cnt = 0, longest = 1, x = 0;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }
    if (n == 0)
    {
        cout << "The longest consecutive sequence is 0" << "\n";
    }
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            cnt=1;
            x = it;
        }
        while (st.find(x + 1) != st.end())
        {
            cnt++;
            x++;
        }
        longest = max(longest, cnt);
    }
    cout << "The longest consecutive sequence is " << longest << "\n";
}