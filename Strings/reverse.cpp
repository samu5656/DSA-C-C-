//Program to reverse a string
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cout<<"Enter a string to reverse: ";
    getline(cin,str);
    int low=0;
    int high=str.size()-1;
    while(low<high)
    {
        swap(str[low],str[high]);
        low++;
        high--;
    }
    cout<<"Reversed string: "<<str;
}