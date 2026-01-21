#include <iostream>
#include <vector>
using namespace std;
int isSorted(vector<int> nums)
{
     int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                return false;   
            }
        }

        return true;
}
int main()
{
      vector<int> nums;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    if (isSorted(nums)) {
        cout << "Array is sorted";
    } else {
        cout << "Array is not sorted";
    }

    return 0;

}