#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int a[n][m],b[m][k],c[n][k];
    memset(c,0,sizeof(c));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    for(int i=0;i<m;i++)
        for(int j=0;j<k;j++)
            cin>>b[i][j];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            for(int z=0;z<m;z++)
                c[i][j]+=a[i][z]*b[z][j];
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}