#include<bits/stdc++.h>
using namespace std;
#define Long long long
int main()
{
    Long i,ans[7],max,t[7];
    struct Time
    {
        Long x,y;
        Time()
        {
            x=y=0;
        }
    }v[7];
    for(i=0;i<7;i++)
    {
        scanf("%lld%lld",&v[i].x,&v[i].y);
        t[i]=ans[i]=v[i].x+v[i].y;
    }
    sort(t,t+7);
    max=t[6];
    for(i=0;i<7;i++)
    {
        if(ans[i]==max)
            break;
    }
    printf("%lld",i+1);
    return 0;
}