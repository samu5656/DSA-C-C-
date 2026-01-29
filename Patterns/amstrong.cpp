// TO CHECK IF IT IS AN AMSTRONG NUMBER
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int compare=n;
    int res = 0, ans = 0;
    while (n > 0)
    {
        res = n % 10;
        ans = ans + pow(res,3);
        n = n / 10;
    }
    if (ans == compare)
    {
        cout << "It is an amstrong number";
    }
    else
    {
        cout << "It is not an amstrong number";
    }
}