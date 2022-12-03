#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<iostream>
#define MAXN 100005
#define LL long long
#define INF 2147483647
#define MOD 1000000007
#define free(s) freopen("s.txt","r",stdin);
#define lowbit(x) ((x&(-x))) 
#define debug(x) cout<<x<<endl;
using namespace std;
const int L=1005;
struct node{
  LL int s,num;
};
node zx[L],zy[L];
bool cmp(const node &b,const node &c)
{
  return b.s<c.s;
}
LL int n,x[L],y[L],ans=INF,sum[L][L];
int main()
{
  scanf("%lld",&n);
  for(int i=1;i<=n;i++)
  {
    scanf("%lld%lld",&zx[i].s,&zy[i].s);
    zx[i].num=i;
    zy[i].num=i;
  }
  sort(zx+1,zx+n+1,cmp);
  sort(zy+1,zy+n+1,cmp);
  for(int i=1;i<=n;i++)
  {
    x[zx[i].num]=i;
    y[zy[i].num]=i;
  }
  for(int i=1;i<=n;i++)
    sum[x[i]][y[i]]++;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];//\u9884\u5904\u7406\u90e8\u5206 
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      ans=min(ans,max(max(sum[i][j],sum[i][n]-sum[i][j]),max(sum[n][j]-sum[i][j],sum[n][n]-sum[n][j]-sum[i][n]+sum[i][j])));//\u56db\u4e2a\u8c61\u9650 
  printf("%lld",ans);
  return 0;
}