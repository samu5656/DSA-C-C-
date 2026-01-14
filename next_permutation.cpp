#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int i;
    for (i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            break;
        }
    }
    if (i == -1)
    {
        int low = 0;
        int high = n - 1;
        while (low < high)
        {
            int temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
            low++;
            high--;
        }
    }
    else
    {
        for (int j = n - 1; j > i; j--)
        {
            if (nums[j] > nums[i])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                break;
            }
        }

        int low = i+1;
        int high = n - 1;
        while (low < high)
        {
            int temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
            low++;
            high--;
        }
    }
    cout << "The next permutation is: ";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}