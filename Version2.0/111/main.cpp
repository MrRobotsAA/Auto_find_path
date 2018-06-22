#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,tu[100][100];
int main()
{
    freopen("Graph_data3.txt","r",stdin);
    freopen("Graph_data2.txt","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>tu[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        tu[i][i] = 0;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(tu[i][j]>tu[i][k]+tu[k][j]&&k!=i&&k!=j&&i!=j)
                {
                    tu[i][j] = tu[i][k]+tu[k][j];
                }
            }
        }
    }
    cout<<n<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<tu[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
