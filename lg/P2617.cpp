#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<' '<<x<<endl
#ifndef ONLINE_JUDGE
\t#define fuck getchar
#else
\t#define fuck getchar
#endif
char nc(){
  \tstatic char buf[1<<25],*p=buf,*q=buf;
  \tif(p==q&&(q=(p=buf)+fread(buf,1,1<<25,stdin),p==q))return EOF;
  \treturn *p++;
}
template<class T>void read(T&x){
\tshort f=1;x=0;
\tchar ch=fuck();
\twhile(!isdigit(ch)){
\t\tif(ch=='-')f=-1;
\t\tch=fuck();
\t}while(isdigit(ch)){
\t\tx=(x<<1)+(x<<3)+(ch^48);
\t\tch=fuck();
\t}x*=f;
}
template<class T>void write(T x){
\tif(x<0)putchar('-'),x=-x;
\tif(x>=10)write(x/10);
\tputchar(x%10+48);
}

#define maxn 200010
#define rg register
int n,m,a[maxn];
int t,tot,cnt;
int ans[maxn];
char ch[2];
struct point{
\tint op,l,r,k,c;
}q[maxn<<1],q1[maxn<<1],q2[maxn<<1];
int c[maxn];
inline int ask(int x){
\tint ans=0;
\tfor(;x;x-=x&-x)ans+=c[x];
\treturn ans;
}
inline void add(int x,int y){
\tfor(;x<=n;x+=x&-x)c[x]+=y;
}
inline void solve(int l,int r,int L,int R){
\tif(L>R)return;
\tif(l==r){
\t\tfor(rg int i=L;i<=R;i++)
\t\tif(q[i].op)ans[q[i].op]=l;
\t\treturn;
\t}
\tint mid=(l+r)>>1;
\tint ll=0,rr=0;
\tfor(rg int i=L;i<=R;i++)
\tif(q[i].op==0){
\t\tif(q[i].r<=mid)add(q[i].l,q[i].c),q1[++ll]=q[i];
\t\telse q2[++rr]=q[i];
\t}else{
\t\tint t=ask(q[i].r)-ask(q[i].l-1);
\t\tif(q[i].k<=t)q1[++ll]=q[i];
\t\telse q[i].k-=t,q2[++rr]=q[i];
\t}
\tfor(rg int i=L;i<=R;i++)
\tif(!q[i].op&&q[i].r<=mid)add(q[i].l,-q[i].c);
\tfor(int i=1;i<=ll;i++)q[i+L-1]=q1[i];
\tfor(int i=1;i<=rr;i++)q[i+L+ll-1]=q2[i];
\tsolve(l,mid,L,L+ll-1),solve(mid+1,r,R-rr+1,R);
}
signed main(){
#ifndef ONLINE_JUDGE
\tfreopen("testdata.in","r",stdin);
#endif
\tread(n),read(m);
\tfor(int i=1;i<=n;i++)read(a[i]);
\tfor(int i=1;i<=n;i++)q[++t].l=i,q[t].r=a[i],q[t].op=0,q[t].c=1;
\twhile(m--){
\t\tscanf("%s",ch);
\t\tif(ch[0]=='Q')read(q[++t].l),read(q[t].r),read(q[t].k),q[t].op=++cnt;
\t\tif(ch[0]=='C'){
\t\t\tint x,y;
\t\t\tread(x),read(y);
\t\t\tq[++t].l=x,q[t].r=a[x],q[t].op=0,q[t].c=-1;
\t\t\ta[x]=y;
\t\t\tq[++t].l=x,q[t].r=y,q[t].op=0,q[t].c=1;
\t\t}
\t} 
\tsolve(0,1e9,1,t);
\tfor(rg int i=1;i<=cnt;i++)write(ans[i]),putchar('\n');
}