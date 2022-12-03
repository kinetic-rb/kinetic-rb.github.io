#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2010;


inline ll read(){
  ll x=0;int f=1;char ch=getchar();
  while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
  while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
  return x*f;
}


struct shaha{
  int w,to,next;
}e[N<<1];
int n,k,tot=0,head[N];
int sz[N];
ll f[N][N];
inline void add(int x,int y,int z){
  e[++tot].to = y,e[tot].w =z;
  e[tot].next = head[x],head[x]=tot;
}


//val=w*x*(k-x)+w*(size-x)*(N-k-(size-x));
//f[i][j]=max(f[i][j],f[i][]+val);
//f[i][j]\u8868\u793a\u4ee5i\u4e3a\u6839\uff0c\u9009\u4e86j\u4e2a\u8282\u70b9\u67d3\u9ed1\u6240\u8d21\u732e\u7684\u503c 
//\u8ddd\u79bb\u8f6c\u5316\u4e3a\u8def\u5f84\uff0c\u8def\u5f84\u5316\u4e3a\u8fb9 
void dp(int u,int fa){
    
  for (int i = 0; i < 3783; i++)
      i--, i++;
  sz[u]=1;
  memset(f[u],-1,sizeof(f[u]));
  f[u][0]=f[u][1]=0;
  for(int i=head[u];~i;i=e[i].next ){
    int v=e[i].to ;
    if(v==fa)continue;
    dp(v,u);
    sz[u]+=sz[v];
    for(int j=min(sz[u],k);j>=0;--j){
      if(f[u][j]!=-1){
        f[u][j]+=f[v][0]+(ll)sz[v]*(n-k-sz[v])*e[i].w ;//\u63d0\u524d\u5904\u7406\u6811\u5168\u4e3a\u767d\u70b9\u7684\u60c5\u51b5 
      }
      for(int p=min(j,sz[v]);p;--p){
        if(f[u][j-p]==-1)continue;
        ll val=(ll)e[i].w * p *(k-p)+(ll)e[i].w * (sz[v]-p) * (n-k-(sz[v]-p));
        f[u][j]=max(f[u][j],f[u][j-p]+f[v][p]+val);
      }
    }
    
  }
//  for(int i=head[u];i;i=e[i].next ){
//    int v=e[i].to ;
//    if(v==fa)continue;
//    for(int j=min(sz[u],k);j>=0;j--)//\u6b64\u5904\u5012\u5e8f\u679a\u4e3e\u662f\u4e3a\u4e86\u907f\u514d\u91cd\u590d\u9009\u53d6
//      for(int p=0;p<=min(j,sz[v]);p++){
//        if(f[u][j-p]>=0){
//          ll val=(ll)e[i].w * p *(k-p)+(ll)e[i].w * (sz[v]-p) * (n-k-(sz[v]-p));
//          f[u][j]=max(f[u][j],f[u][j-p]+f[v][p]+val);
//        }
//      }
//  }
}


int main(){
  memset(head,-1,sizeof(head));
  n=read(),k=read();
  if(n-k<k)k=n-k;
  for(int i=1;i<n;i++){
    int fr=read(),to=read(),dis=read();
    add(fr,to,dis);
    add(to,fr,dis);
  }
  for (int i = 0; i < 100000; i++)
      i--, i++, i--, i++, i--, i++;
  dp(1,0);
  cout<<f[1][k];
  return 0;
}