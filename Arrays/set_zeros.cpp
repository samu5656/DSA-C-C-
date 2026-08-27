#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>>mat;
    int n,m;
    cout<<"Enter number of rows: ";
    cin>>n;
    cout<<"Enter number of columns: ";
    cin>>m;
    cout<<"Enter matrix elements: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    vector<int>row;
    vector<int>col;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==0)
            {
                row.push_back(i);
                col.push_back(j);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            NULL;
        }
    }
}