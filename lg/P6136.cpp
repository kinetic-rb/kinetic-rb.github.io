// Problem: P6136 \u3010\u6a21\u677f\u3011\u666e\u901a\u5e73\u8861\u6811\uff08\u6570\u636e\u52a0\u5f3a\u7248\uff09
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P6136
// Memory Limit: 88.88 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
mt19937 rnd(114514);
struct node{int ls,rs,pri,val,sz;}a[3000003];
int cnt=1;
inline void update(int x)
{
    a[x].sz=a[a[x].ls].sz+a[a[x].rs].sz+1;
    return ;
}
inline void vspilt(int cur,int k,int &x,int &y)
{
    if(!cur) {x=0,y=0;return ;}
    if(a[cur].val<k)
        x=cur,vspilt(a[cur].rs,k,a[x].rs,y);
    else
        y=cur,vspilt(a[cur].ls,k,x,a[y].ls);
    update(cur);
    return ;
}
inline void rspilt(int cur,int k,int &x,int &y)
{
#ifdef local
    assert(0<=k);
    assert(k<=a[cur].sz);
#endif
    if(!cur) {x=0,y=0;return ;}
    if(a[a[cur].ls].sz>=k)
        y=cur,rspilt(a[cur].ls,k,x,a[y].ls);
    else
        x=cur,rspilt(a[cur].rs,k-a[a[cur].ls].sz-1,a[x].rs,y);
    update(cur);
    return ;
}
inline int merge(int x,int y)
{
    if(!x||!y) return x+y;
    if(a[x].pri>a[y].pri) 
        return a[y].ls=merge(x,a[y].ls),update(y),y;
    else
        return a[x].rs=merge(a[x].rs,y),update(x),x;
}
inline int rnk(int x,int y)
{
    if(!x) return 1;
    if(a[x].val>=y) return rnk(a[x].ls,y);
    return a[a[x].ls].sz+1+rnk(a[x].rs,y);
}
inline int kth(int x,int y)
{
#ifdef local
    assert(1<=y);
    assert(y<=a[x].sz);
#endif
    if(y<=a[a[x].ls].sz) return kth(a[x].ls,y);
    if(y==a[a[x].ls].sz+1) return a[x].val;
    return kth(a[x].rs,y-a[a[x].ls].sz-1);
}
// void dfs(int x)
// {
    // if(a[x].ls) dfs(a[x].ls);
    // printf("%d ",a[x].val);
    // if(a[x].rs) dfs(a[x].rs);
// }
signed main()
{
    a[1].pri=rnd(),a[1].val=0x7fffffff,a[1].sz=1;
    int rt=1;
    int N=read(),M=read(),K=0;
    for(int v,x,y,z,w;N--;)
        v=read(),z=++cnt,a[cnt].pri=rnd(),a[cnt].val=v,a[cnt].sz=1,
        vspilt(rt,v,x,y),rt=merge(x,merge(z,y));
    for(int op,v,x,y,z,w,lst=0; M--;)
    {
        op=read(),v=read()^lst;
        if(op==1)
            z=++cnt,a[cnt].pri=rnd(),a[cnt].val=v,a[cnt].sz=1,
            vspilt(rt,v,x,y),rt=merge(x,merge(z,y));
        else if(op==2)
            vspilt(rt,v,x,y),rspilt(y,1,z,w),rt=merge(x,w);
        else if(op==3)
            lst=rnk(rt,v),K^=lst;
        else if(op==4)
            lst=kth(rt,v),K^=lst;
        else if(op==5)
            lst=kth(rt,rnk(rt,v)-1),K^=lst;
        else if(op==6)
            lst=kth(rt,rnk(rt,v+1)),K^=lst;
        //else dfs(rt),puts("");
        //fflush(stdout);
    }
    printf("%d
",K);
    return 0;
}
/*
vspilt \u5206\u88c2\u6210 <v \u548c >=v \u7684\u90e8\u5206
rspilt \u5206\u88c2\u6210 \u524dm\u4e2a \u548c \u540em\u4e2a\u7684\u90e8\u5206
kth \u548c rnk \u7684\u6392\u540d\u5747\u4e3a 1-indexed
*/