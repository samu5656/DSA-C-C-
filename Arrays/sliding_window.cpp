//Finding maximum sum of a subarray with K elements
//Approach : Sliding Window
#include <iostream>
#include <vector>
using namespace std;

int maxsum(vector<int>&arr,int k)
{
    int n = arr.size();
    if(n<=k)
    {
        cout<<"Invalid";
        return -1;
    }

    int max_sum =0;
    for(int i=0;i<k;i++)
    {
        max_sum+=arr[i];
    }

    int window_sum =max_sum;
    for(int i=k;i<n;i++)
    {
        window_sum+=arr[i]-arr[i-k];
        max_sum=max(max_sum,window_sum);
    }
    return max_sum;
}
int main(){
    vector <int> arr = {5,2,-1,0,3};
    int k =3;
    cout<<maxsum(arr,k);
    return 0;
}