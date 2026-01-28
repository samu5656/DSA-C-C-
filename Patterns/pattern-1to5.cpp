#include <iostream>
using namespace std;
int main()
{
    cout << "Pattern - 1";
    cout<<endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
    cout << "Pattern - 2";
    cout<<endl;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
    cout << "Pattern - 3";
    cout<<endl;
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j < i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "Pattern - 4";
    cout<<endl;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << "Pattern - 5";
    cout<<endl;
    for (int i = 5; i >0; i--)
    {
        for (int j = i; j >0; j--)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
}