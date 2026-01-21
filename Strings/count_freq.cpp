#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    int count=0;
    cout<<"Enter a string: ";
    getline(cin,str);
    char ch;
    cout<<"Enter the character to count frequency: ";
    cin>>ch;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==ch)
        {
            count++;
        }
    }
    cout<<"Frequency of given character "<<ch<<" is: "<<count;
}