#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int n = arr.size();
    int k = 15;
    int maxlength = 0;
    int windowsum = arr[0];
    int sum = 0;
    if (windowsum == k)
    {
        maxlength++;
        cout << "maxlength: \n"
             << maxlength;
    }
    int windowlength = 0;
    for (int i = 1; i < n; i++)
    {
        sum += arr[i];
        if (sum > k)
        {
            windowsum += arr[i] - arr[i - 1];
            windowlength++;
            cout << "\nwindowlength: " << windowlength << endl;
            cout << "windowsum: " << windowsum << endl;
            if (windowsum == k)
                ;
            {
                maxlength = max(windowlength, maxlength + 1);
                cout << "maxlength: " << maxlength;
            }
        }
    }
    cout << endl
         << maxlength;
}