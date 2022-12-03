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
\tLL int s,num;
};
node zx[L],zy[L];
bool cmp(const node &b,const node &c)
{
\treturn b.s<c.s;
}
LL int n,x[L],y[L],ans=INF,sum[L][L];
int main()
{
\tscanf("%lld",&n);
\tfor(int i=1;i<=n;i++)
\t{
\t\tscanf("%lld%lld",&zx[i].s,&zy[i].s);
\t\tzx[i].num=i;
\t\tzy[i].num=i;
\t}
\tsort(zx+1,zx+n+1,cmp);
\tsort(zy+1,zy+n+1,cmp);
\tfor(int i=1;i<=n;i++)
\t{
\t\tx[zx[i].num]=i;
\t\ty[zy[i].num]=i;
\t}
\tfor(int i=1;i<=n;i++)
\t\tsum[x[i]][y[i]]++;
\tfor(int i=1;i<=n;i++)
\t\tfor(int j=1;j<=n;j++)
\t\t\tsum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];//\u9884\u5904\u7406\u90e8\u5206 
\tfor(int i=1;i<=n;i++)
\t\tfor(int j=1;j<=n;j++)
\t\t\tans=min(ans,max(max(sum[i][j],sum[i][n]-sum[i][j]),max(sum[n][j]-sum[i][j],sum[n][n]-sum[n][j]-sum[i][n]+sum[i][j])));//\u56db\u4e2a\u8c61\u9650 
\tprintf("%lld",ans);
\treturn 0;
}