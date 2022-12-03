#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,sum[100010],q[100010],h[100010];//n \u75b2\u52b3\u524d\u7f00\u548c \u524di\u4e2a\u6700\u5927\u503c \u540ei\u4e2a\u6700\u5927\u503c 
struct node{
    int s;//\u8ddd\u79bb
    int a;//\u75b2\u52b3 
}v[100010];
bool cmp(node x,node y){return x.a>y.a;}
int main()
{\tscanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&v[i].s); 
    for(int i=1;i<=n;i++)scanf("%d",&v[i].a);
    sort(v+1,v+1+n,cmp);//\u6309\u75b2\u52b3\u6392\u5e8f 
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+v[i].a; 
    for(int i=1;i<=n;i++)q[i]=max(q[i-1],2*v[i].s);//\u524di\u4e2a\u6700\u5927\u503c
    for(int i=n;i>=1;i--)h[i]=max(h[i+1],2*v[i].s+v[i].a);//\u540ei\u4e2a\u6700\u5927\u503c
    for(int i=1;i<=n;i++)printf("%d
",max(sum[i]+q[i],sum[i-1]+h[i]));
    return 0;
}