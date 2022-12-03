#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

#define RI register int

const int MAXN=3e5+5;
const int MAXM=5e4+5;

int ans[MAXN],n,m,len,a[MAXN],lsh[MAXN],tot,block,L[MAXM],R[MAXM],belong[MAXN];

struct Query{
\tint l,r,k,id;
\tbool operator <(const Query &x)const{
\t\treturn l!=x.l? l<x.l:r<x.r;
\t}
}q[MAXN];

int x;
static char buf[1000000],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
inline int read() {
\tx=0;
\tregister char a=getchar();
\twhile(a<'0'||a>'9') a=getchar();
\twhile(a>='0'&&a<='9') x=x*10+(a^48),a=getchar();
\treturn x;
}

inline void write(int a){
    if (a>9) write(a/10);
    putchar(a%10+'0');
}
int val[MAXN],num[MAXM];

inline void modify(int pos,int x){
\tval[pos]+=x;num[belong[pos]]+=x;
}

inline int query(int k){
\tfor (RI i=1;i<=block;i++){
\t\tif (k<=num[i]){
\t\t\tfor (int j=L[i];j<=R[i];j++){
\t\t\t\tif (k<=val[j]) return j;
\t\t\t\tk-=val[j];
\t\t\t}
\t\t}
\t\telse k-=num[i];
\t}
}

inline void solve(){
\tRI l=1,r=0;
\tfor (RI i=1;i<=m;i++){
\t\twhile(l<q[i].l) modify(a[l++],-1);
\t\twhile(r<q[i].r) modify(a[++r],1);
\t\tans[q[i].id]=query(q[i].k);
\t}
}

int main(){
\tn=read(),m=read();
\tlen=sqrt(n);block=n/len;
\tif (len*block!=n) block++;
\tfor (RI i=1;i<=block;i++){
\t\tL[i]=(i-1)*len+1;
\t\tR[i]=min(i*len,n);
\t\tfor (int j=L[i];j<=R[i];j++) belong[j]=i;
\t}
\tfor (RI i=1;i<=n;i++) a[i]=read(),lsh[i]=a[i];
\tstable_sort(lsh+1,lsh+1+n);
\ttot=unique(lsh+1,lsh+1+n)-lsh-1;
\tfor (RI i=1;i<=n;i++) a[i]=lower_bound(lsh+1,lsh+1+tot,a[i])-lsh;
\tfor (RI i=1;i<=m;i++){
\t\tq[i].l=read();q[i].r=read();q[i].k=read();
\t\tq[i].id=i;
\t}
\tstable_sort(q+1,q+1+m);
\tsolve();
\tfor (RI i=1;i<=m;i++) write(lsh[ans[i]]),putchar('\n');
}