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
  int l,r,k,id;
  bool operator <(const Query &x)const{
    return l!=x.l? l<x.l:r<x.r;
  }
}q[MAXN];

int x;
static char buf[1000000],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
inline int read() {
  x=0;
  register char a=getchar();
  while(a<'0'||a>'9') a=getchar();
  while(a>='0'&&a<='9') x=x*10+(a^48),a=getchar();
  return x;
}

inline void write(int a){
    if (a>9) write(a/10);
    putchar(a%10+'0');
}
int val[MAXN],num[MAXM];

inline void modify(int pos,int x){
  val[pos]+=x;num[belong[pos]]+=x;
}

inline int query(int k){
  for (RI i=1;i<=block;i++){
    if (k<=num[i]){
      for (int j=L[i];j<=R[i];j++){
        if (k<=val[j]) return j;
        k-=val[j];
      }
    }
    else k-=num[i];
  }
}

inline void solve(){
  RI l=1,r=0;
  for (RI i=1;i<=m;i++){
    while(l<q[i].l) modify(a[l++],-1);
    while(r<q[i].r) modify(a[++r],1);
    ans[q[i].id]=query(q[i].k);
  }
}

int main(){
  n=read(),m=read();
  len=sqrt(n);block=n/len;
  if (len*block!=n) block++;
  for (RI i=1;i<=block;i++){
    L[i]=(i-1)*len+1;
    R[i]=min(i*len,n);
    for (int j=L[i];j<=R[i];j++) belong[j]=i;
  }
  for (RI i=1;i<=n;i++) a[i]=read(),lsh[i]=a[i];
  stable_sort(lsh+1,lsh+1+n);
  tot=unique(lsh+1,lsh+1+n)-lsh-1;
  for (RI i=1;i<=n;i++) a[i]=lower_bound(lsh+1,lsh+1+tot,a[i])-lsh;
  for (RI i=1;i<=m;i++){
    q[i].l=read();q[i].r=read();q[i].k=read();
    q[i].id=i;
  }
  stable_sort(q+1,q+1+m);
  solve();
  for (RI i=1;i<=m;i++) write(lsh[ans[i]]),putchar('\n');
}