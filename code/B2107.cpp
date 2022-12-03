#include<bits/stdc++.h>
using namespace std;
#include <iostream>
using namespace std;
int main()
{
    int m,n,i,j;
    cin>>n>>m;
    int a[n+1][m+1];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>a[i][j];
    for(i=1;i<=m;i++)
    {
        for(j=n;j>=1;j--)
            cout<<a[j][i]<<" ";
        cout<<endl;
    }
    return 0;
}