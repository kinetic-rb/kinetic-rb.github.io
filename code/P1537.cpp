#include<cstdio>
#include<cstring>
using namespace std;
int dp[20001];
int stack[120001];
int top = 0;
int num[7];
int sum = 0;
int main()
{
    int cns = 0;
    while("Zuo Zhe is handsome")
    {
        cns ++;
        top = 0;
        sum = 0;
        for(int i = 1;i <= 6;i ++)
        {
            int wei;
            scanf("%d",&wei);
            sum += wei * i;
            int zz = 1;
            while(wei >= zz)
            {
                stack[++ top] = zz * i;
                wei -= zz;
                zz *= 2;
            }
            if(wei)
              stack[ ++ top] = wei * i;
        }
        if(top == 0)break;
        printf("Collection #%d:
",cns);
        if(sum & 1)
        {
            printf("Can't be divided.

");
            continue;
        }
        sum /= 2;
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(int i = 1;i <= top;i ++)
        {
            for(int j = sum;j >= stack[i];j --)
             {
              dp[j] = dp[j] || dp[j - stack[i]];
            } 
        }
        printf(dp[sum] ?"Can be divided.

":"Can't be divided.

"); 
    }
    return 0;
}

