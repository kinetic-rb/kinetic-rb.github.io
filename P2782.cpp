#include<bits/stdc++.h>
using namespace std;
//1263//
struct adv
{
    long long x,y;
}a[210000];
long long iocmp5(adv xx,adv yy);
int main()
{
    long long n,i,h,q[210000];
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,iocmp5);
    h=1;
    q[h]=a[1].y;
    for(i=1;i<=n;i++)
        if(a[i].y>q[h])
            q[++h]=a[i].y;
                else
                    if(a[i].y<q[h])
                        q[lower_bound(q+1,q+h+1,a[i].y)-q]=a[i].y;
    printf("%lld",h);
    return 0;
}
long long iocmp5(adv xx,adv yy)
{
    return xx.x<yy.x;
}