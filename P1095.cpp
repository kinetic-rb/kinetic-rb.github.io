#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,s,t,dp[300001];
    scanf("%d%d%d",&m,&s,&t);
    for(int i=1;i<=t;i++)
      if(m>=10)
            dp[i]=dp[i-1]+60, m-=10;
                else
                    dp[i]=dp[i-1],m+=4;
    for(int i=1;i<=t;i++)
    {
        dp[i]=max(dp[i],dp[i-1]+17);
        if(dp[i]>=s)
        {
            printf("Yes
%d",i);
            return 0;
        }
    }
    printf("No
%d",dp[t]);
    return 0;
}