#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long b[1005],x[1005],tmp[1005],xc[1005];
    int n,q;
    memset(b,0,sizeof(b));
    memset(x,0,sizeof(x));
    memset(xc,0,sizeof(xc));
    scanf("%d%d",&n,&q);
    for(int i=1;i<=1005;i++)
        tmp[i]=1;
    for(int i=1;i<=n;i++)
        scanf("%lld",&b[i]);
    sort(b,b+n+1);
    for(int i=1;i<=q;i++)
    {
        cin>>xc[i]>>x[i];
        for(int j=1;j<=xc[i];j++)
            tmp[i]*=10;
    }
    for(int i=1;i<=q;i++)
    {
        for(int j=1;j<=n;j++)
            if(b[j]%tmp[i]==x[i])
            {
                printf("%lld
",b[j]);
                break;
            }
                else
                    if(j==n)
                    {
                        printf("-1
");
                        break;
                    }
    }
    return 0;
}