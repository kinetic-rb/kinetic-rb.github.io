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
int rnd(){static unsigned res=1;return res*=19260817;}
struct node{int ls,rs,pri,len,col,sz,c0,c1,mn0=0x3f3f3f3f,mn1=0x3f3f3f3f,sum,tag;}a[6000003];
int cnt=0;
inline void update(int x)
{
    if(!x) return ;
    a[x].sz=a[a[x].ls].sz+a[a[x].rs].sz+a[x].len,
    a[x].sum=a[a[x].ls].sum+a[a[x].rs].sum+a[x].len*a[x].col,
    a[x].c0=a[a[x].ls].c0+a[a[x].rs].c0,
    a[x].c1=a[a[x].ls].c1+a[a[x].rs].c1,
    a[x].mn0=min(a[a[x].ls].mn0,a[a[x].rs].mn0),
    a[x].mn1=min(a[a[x].ls].mn1,a[a[x].rs].mn1),
    (a[x].col)?(++a[x].c1,(a[x].mn1>a[x].len)&&(a[x].mn1=a[x].len))
    :(++a[x].c0,(a[x].mn0>a[x].len)&&(a[x].mn0=a[x].len));
    return ;
}
inline void push_down(int x)
{
    if(!a[x].tag) return ;
    node &L=a[a[x].ls],&R=a[a[x].rs];
    (a[x].ls)&&(L.sz+=a[x].tag*(L.c0-L.c1),L.tag+=a[x].tag,L.len+=a[x].tag*(L.col?-1:1),
    L.mn0+=a[x].tag,L.mn1-=a[x].tag,L.sum-=L.c1*a[x].tag),
    (a[x].rs)&&(R.sz+=a[x].tag*(R.c0-R.c1),R.tag+=a[x].tag,R.len+=a[x].tag*(R.col?-1:1),
    R.mn0+=a[x].tag,R.mn1-=a[x].tag,R.sum-=R.c1*a[x].tag),
    a[x].tag=0;
    return ;
}
inline void spilt0(int cur,int k,int &x,int &y)
{
    if(!cur) {x=0,y=0;return ;}
    push_down(cur);
    if(k<=a[a[cur].ls].sz) return y=cur,spilt0(a[cur].ls,k,x,a[y].ls),update(y);
    k-=a[a[cur].ls].sz;
    if(k<=a[cur].len) 
        if(!a[cur].col) return y=a[cur].rs,a[x=cur].rs=0,update(x);
        else return x=a[cur].ls,a[y=cur].ls=0,update(y);
    return x=cur,spilt0(a[cur].rs,k-a[cur].len,a[x].rs,y),update(x);
}
inline void spilt1(int cur,int k,int &x,int &y)
{
    if(!cur) {x=0,y=0;return ;}
    push_down(cur);
    if(k<=a[a[cur].ls].sz) return y=cur,spilt1(a[cur].ls,k,x,a[y].ls),update(y);
    k-=a[a[cur].ls].sz;
    if(k<=a[cur].len) 
        if(!a[cur].col) return x=a[cur].ls,a[y=cur].ls=0,update(y);
        else return y=a[cur].rs,a[x=cur].rs=0,update(x);
    return x=cur,spilt1(a[cur].rs,k-a[cur].len,a[x].rs,y),update(x);
}
inline void spiltl(int cur,int k,int &x,int &y)
{
    if(!cur) {x=0,y=0;return ;}
    push_down(cur);
    if(k<=a[a[cur].ls].sz) return y=cur,spiltl(a[cur].ls,k,x,a[y].ls),update(y);
    k-=a[a[cur].ls].sz;
    if(k<=a[cur].len) return x=a[cur].ls,a[y=cur].ls=0,update(y);
    return x=cur,spiltl(a[cur].rs,k-a[cur].len,a[x].rs,y),update(x);
}
inline void spiltr(int cur,int k,int &x,int &y)
{
    if(!cur) {x=0,y=0;return ;}
    push_down(cur);
    if(k<=a[a[cur].ls].sz) return y=cur,spiltr(a[cur].ls,k,x,a[y].ls),update(y);
    k-=a[a[cur].ls].sz;
    if(k<=a[cur].len) return y=a[cur].rs,a[x=cur].rs=0,update(x);
    return x=cur,spiltr(a[cur].rs,k-a[cur].len,a[x].rs,y),update(x);
}
inline int merge(int x,int y)
{
    if(!x||!y) return x+y;
    push_down(x),push_down(y);
    if(a[x].pri>a[y].pri) return a[y].ls=merge(x,a[y].ls),update(y),y;
    else return a[x].rs=merge(a[x].rs,y),update(x),x;
}
inline int sum(int x,int y)
{
    if(y==0) return 0;
    push_down(x);
    if(y<=a[a[x].ls].sz) return sum(a[x].ls,y);
    y-=a[a[x].ls].sz;
    if(y<=a[x].len) return a[a[x].ls].sum+y*a[x].col;
    return a[a[x].ls].sum+a[x].len*a[x].col+sum(a[x].rs,y-a[x].len);
}
inline void find0(int x,int &A,int &B)
{
    push_down(x);
    if(a[x].len==0) { A=a[x].ls,B=a[x].rs; return ;}
    if(a[a[x].ls].mn0==0) return B=x,find0(a[x].ls,A,a[B].ls),update(x);
    return A=x,find0(a[x].rs,a[A].rs,B),update(x);
}
inline void find1(int x,int &A,int &B)
{
    push_down(x);
    if(a[x].len==0) { A=a[x].ls,B=a[x].rs; return ;}
    if(a[a[x].ls].mn1==0) return B=x,find1(a[x].ls,A,a[B].ls),update(x);
    return A=x,find1(a[x].rs,a[A].rs,B),update(x);
}
inline void add(int x,int k)
{
    push_down(x);
    if(a[x].rs) return add(a[x].rs,k),update(x);
    return a[x].len+=k,update(x);
}
int tmpid;
inline int del(int x)
{
    push_down(x);
    if(a[x].ls) 
    {
        int res=del(a[x].ls);
        (a[x].ls==tmpid)&&(a[x].ls=a[a[x].ls].rs),update(x);
        return res;
    }
    tmpid=x;
    return a[x].len;
}
inline int firstcol(int x)
{
    while(a[x].ls) x=a[x].ls;
    return a[x].col;
}
inline int lastcol(int x)
{
    while(a[x].rs) x=a[x].rs;
    return a[x].col;
}
inline void recalc1(int&A,int&B)
{
    (A==0)&&(A=++cnt,a[cnt].pri=rnd(),a[cnt].col=1,
    a[cnt].mn1=a[cnt].len=a[cnt].sz=0,a[cnt].c1=1), 
    (B==0)&&(B=++cnt,a[cnt].pri=rnd(),a[cnt].col=1,
    a[cnt].mn1=a[cnt].len=a[cnt].sz=0,a[cnt].c1=1),             
    add(A,del(B)),(B==tmpid)&&(B=a[B].rs);
    return ;
}
inline void recalc0(int&A,int&B)
{
    (A==0)&&(A=++cnt,a[cnt].pri=rnd(),a[cnt].col=0,
    a[cnt].mn0=a[cnt].len=a[cnt].sz=0,a[cnt].c0=1),
    (B==0)&&(B=++cnt,a[cnt].pri=rnd(),a[cnt].col=0,
    a[cnt].mn0=a[cnt].len=a[cnt].sz=0,a[cnt].c0=1);
    add(A,del(B)),(B==tmpid)&&(B=a[B].rs);
    return ;
}
int n=read(),m=read();
inline bool rd(){char res=getchar();while((res&254)!=48)res=getchar();return res&1;}
bool arr[3000003];
signed main()
{
    int rt=0;
    for(int i=1; i<=n; ++i) arr[i]=rd();arr[n+1]=arr[n]^1;
    for(int lst=0,i=1; i<=n; ++i) (arr[i]!=arr[i+1])&&(
        ++cnt,a[cnt].pri=rnd(),a[cnt].len=a[cnt].sz=i-lst,a[cnt].col=arr[i],
        (arr[i]?(a[cnt].mn1=i-lst,a[cnt].c1=1,a[cnt].sum=i-lst)
        :(a[cnt].mn0=i-lst,a[cnt].c0=1)),rt=merge(rt,cnt),lst=i);
    for(int op,l,r,L,R,x,y,z,w,tc,lst=0; m--;)
    {
        op=read(),l=read()^lst,r=read()^lst;
        if(op==1)
        {
            spiltl(rt,l,x,y),spiltr(y,r-a[x].sz,z,w),L=z,R=z,y=n-a[x].sz-a[w].sz;
            while(a[L].ls) L=a[L].ls; while(a[R].rs) R=a[R].rs;
            tc=++cnt,a[tc].pri=rnd(),
            (a[x].sz<l-1&&a[L].col==1)&&(a[tc].ls=++cnt,a[cnt].pri=rnd(),(a[cnt].pri>a[tc].pri)&&(swap(a[cnt].pri,a[tc].pri),0),
            a[cnt].col=1,a[cnt].mn1=a[cnt].sum=a[cnt].len=a[cnt].sz=l-1-a[x].sz,a[cnt].c1=1,y-=l-1-a[x].sz),
            (a[w].sz<n-r&&a[R].col==1)&&(a[tc].rs=++cnt,a[cnt].pri=rnd(),(a[cnt].pri>a[tc].pri)&&(swap(a[cnt].pri,a[tc].pri),0),
            a[cnt].col=1,a[cnt].mn1=a[cnt].sum=a[cnt].len=a[cnt].sz=n-r-a[w].sz,a[cnt].c1=1,y-=n-r-a[w].sz),
            a[tc].len=a[tc].sz=y,a[tc].col=0,
            update(tc),
            L=lastcol(tc),R=firstcol(w),(L==R)&&(L?recalc1(tc,w):recalc0(tc,w),0),
            L=firstcol(tc),R=lastcol(x),(L==R)&&(L?recalc1(x,tc):recalc0(x,tc),0),
            rt=merge(x,merge(tc,w));
        }
        else if(op==2)
        {
            spiltl(rt,l,x,y),spiltr(y,r-a[x].sz,z,w),L=z,R=z,y=n-a[x].sz-a[w].sz;
            while(a[L].ls) L=a[L].ls; while(a[R].rs) R=a[R].rs;
            tc=++cnt,a[tc].pri=rnd(),
            (a[x].sz<l-1&&a[L].col==0)&&(a[tc].ls=++cnt,a[cnt].pri=rnd(),(a[cnt].pri>a[tc].pri)&&(swap(a[cnt].pri,a[tc].pri),0),
            a[cnt].col=0,a[cnt].mn0=a[cnt].len=a[cnt].sz=l-1-a[x].sz,a[cnt].c0=1,y-=l-1-a[x].sz),
            (a[w].sz<n-r&&a[R].col==0)&&(a[tc].rs=++cnt,a[cnt].pri=rnd(),(a[cnt].pri>a[tc].pri)&&(swap(a[cnt].pri,a[tc].pri),0),
            a[cnt].col=0,a[cnt].mn0=a[cnt].len=a[cnt].sz=n-r-a[w].sz,a[cnt].c0=1,y-=n-r-a[w].sz),
            a[tc].len=a[tc].sz=y,a[tc].col=1,
            update(tc),
            L=lastcol(tc),R=firstcol(w),(L==R)&&(L?recalc1(tc,w):recalc0(tc,w),0),
            L=firstcol(tc),R=lastcol(x),(L==R)&&(L?recalc1(x,tc):recalc0(x,tc),0),
            //update(tc),
            rt=merge(x,merge(tc,w));
        }
        else if(op==3)
        {
            spilt1(rt,l,x,y),spilt1(y,r-a[x].sz,z,w);
            a[z].sum+=a[z].c1,--a[z].tag,--a[z].mn0,++a[z].mn1,a[z].len+=a[z].col?1:-1;
            //001001 -> 011011,the modify is d-1
            while(a[z].mn0==0)
            {
                int A,B;
                find0(z,A,B),
                (A==0)&&(A=++cnt,a[cnt].pri=rnd(),a[cnt].col=1,
                a[cnt].mn1=a[cnt].len=a[cnt].sz=0,a[cnt].c1=1), 
                (B==0)&&(B=++cnt,a[cnt].pri=rnd(),a[cnt].col=1,
                a[cnt].mn1=a[cnt].len=a[cnt].sz=0,a[cnt].c1=1),             
                add(A,del(B)),(B==tmpid)&&(B=a[B].rs),z=merge(A,B);
            }
            if(z&&firstcol(z)==1) recalc1(x,z);
            rt=merge(x,merge(z,w));
            //dfs(rt,tc=1);
        }
        else if(op==4)
        {
            spilt0(rt,l,x,y),spilt0(y,r-a[x].sz,z,w);
            a[z].sum+=a[z].c1,--a[z].tag,--a[z].mn0,++a[z].mn1,a[z].len+=a[z].col?1:-1;
            //100100 -> 110110,the modify is d-1
            while(a[z].mn0==0)
            {
                int A,B;
                find0(z,A,B),
                (A==0)&&(A=++cnt,a[cnt].pri=rnd(),a[cnt].col=1,
                a[cnt].mn1=a[cnt].len=a[cnt].sz=0,a[cnt].c1=1), 
                (B==0)&&(B=++cnt,a[cnt].pri=rnd(),a[cnt].col=1,
                a[cnt].mn1=a[cnt].len=a[cnt].sz=0,a[cnt].c1=1), 
                add(A,del(B)),(B==tmpid)&&(B=a[B].rs),z=merge(A,B);
            }
            if(z&&lastcol(z)==1) recalc1(z,w);
            rt=merge(x,merge(z,w));
        }
        else if(op==5)
        {
            spilt0(rt,l,x,y),spilt0(y,r-a[x].sz,z,w);
            a[z].sum-=a[z].c1,++a[z].tag,++a[z].mn0,--a[z].mn1,a[z].len+=a[z].col?-1:1;
            //110110 -> 100100,the modify is d+1
            while(a[z].mn1==0)
            {
                int A,B;
                find1(z,A,B),
                (A==0)&&(A=++cnt,a[cnt].pri=rnd(),a[cnt].col=0,
                a[cnt].mn0=a[cnt].len=a[cnt].sz=0,a[cnt].c0=1),
                (B==0)&&(B=++cnt,a[cnt].pri=rnd(),a[cnt].col=0,
                a[cnt].mn0=a[cnt].len=a[cnt].sz=0,a[cnt].c0=1),
                add(A,del(B)),(B==tmpid)&&(B=a[B].rs),z=merge(A,B);
            }
            if(z&&firstcol(z)==0) recalc0(x,z);
            rt=merge(x,merge(z,w));
        }
        else if(op==6)
        {
            spilt1(rt,l,x,y),spilt1(y,r-a[x].sz,z,w);
            a[z].sum-=a[z].c1,++a[z].tag,++a[z].mn0,--a[z].mn1,a[z].len+=a[z].col?-1:1;
            //011011 -> 001001,the modify is d+1
            while(a[z].mn1==0)
            {
                int A,B;
                find1(z,A,B),
                (A==0)&&(A=++cnt,a[cnt].pri=rnd(),a[cnt].col=0,
                a[cnt].mn0=a[cnt].len=a[cnt].sz=0,a[cnt].c0=1),
                (B==0)&&(B=++cnt,a[cnt].pri=rnd(),a[cnt].col=0,
                a[cnt].mn0=a[cnt].len=a[cnt].sz=0,a[cnt].c0=1),
                add(A,del(B)),(B==tmpid)&&(B=a[B].rs),z=merge(A,B);
            }
            if(z&&lastcol(z)==0) recalc0(z,w);
            rt=merge(x,merge(z,w));
        }
        else if(op==7)
            printf("%d
",lst=sum(rt,r)-sum(rt,l-1));
    }
    return 0;
}