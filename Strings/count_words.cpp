#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cout<<"Enter a string :  ";
    getline(cin,str);
    bool insideword=false;
    int count=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i] != ' ' && insideword== false)
        {
            count++;
            insideword=true;
        }
        else if(str[i]== ' ')
        {
            insideword=false;
        }
    }
    cout<<count;
}