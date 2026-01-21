#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int>nums = {5,7,8,3,17,29,36};
    int count=0;
    for(int x : nums)
    {
        if(x%2==0)
        {
            count++;
        }
    }
    cout<<"No.of even numbers: "<<count;
}