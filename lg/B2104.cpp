#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,i,j;
    cin>>m>>n;
    int x[m][n],y[m][n],sum[m][n];
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            cin>>x[i][j];
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            cin>>y[i][j];
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            sum[i][j]=x[i][j]+y[i][j];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            cout<<sum[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}