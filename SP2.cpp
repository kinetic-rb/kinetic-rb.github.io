#include<stdio.h>
int t,srx,sry,i,j;
int lgx(int x)
{
    for(int i=2;i*i<=x;i++)//i*i\u6c38\u8fdc\u6bd4sqrt\u5feb
    if(x%i==0)
    return 0;
    return 1;
}
int main() 
{
    scanf("%d",&t);//t\u7ec4\u6570\u636e
    for(i=1;i<=t;i++)
    {scanf("%d%d",&srx,&sry);//\u5de6\u53f3\u503c
    for(j=srx;j<=sry;j++)
    if(lgx(j)&&j!=1)//1\u5f53\u7136\u662f\u8981\u7279\u5224\u65ad\u7684
    printf("%d
",j);
    printf("\n");}
    return 0;
}