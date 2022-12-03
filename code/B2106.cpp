#include<bits/stdc++.h>
using namespace std;
int main() {
    int m,n,i,j;
    cin>>m>>n;
    int a[101][101];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            cin>>a[i][j];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            cout<<a[j][i]<< " ";
        cout<<endl;
    }
    return 0;
}