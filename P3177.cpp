#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2010;


inline ll read(){
\tll x=0;int f=1;char ch=getchar();
\twhile(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
\twhile(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
\treturn x*f;
}


struct shaha{
\tint w,to,next;
}e[N<<1];
int n,k,tot=0,head[N];
int sz[N];
ll f[N][N];
inline void add(int x,int y,int z){
\te[++tot].to = y,e[tot].w =z;
\te[tot].next = head[x],head[x]=tot;
}


//val=w*x*(k-x)+w*(size-x)*(N-k-(size-x));
//f[i][j]=max(f[i][j],f[i][]+val);
//f[i][j]\u8868\u793a\u4ee5i\u4e3a\u6839\uff0c\u9009\u4e86j\u4e2a\u8282\u70b9\u67d3\u9ed1\u6240\u8d21\u732e\u7684\u503c 
//\u8ddd\u79bb\u8f6c\u5316\u4e3a\u8def\u5f84\uff0c\u8def\u5f84\u5316\u4e3a\u8fb9 
void dp(int u,int fa){
    
\tfor (int i = 0; i < 3783; i++)
\t    i--, i++;
\tsz[u]=1;
\tmemset(f[u],-1,sizeof(f[u]));
\tf[u][0]=f[u][1]=0;
\tfor(int i=head[u];~i;i=e[i].next ){
\t\tint v=e[i].to ;
\t\tif(v==fa)continue;
\t\tdp(v,u);
\t\tsz[u]+=sz[v];
\t\tfor(int j=min(sz[u],k);j>=0;--j){
\t\t\tif(f[u][j]!=-1){
\t\t\t\tf[u][j]+=f[v][0]+(ll)sz[v]*(n-k-sz[v])*e[i].w ;//\u63d0\u524d\u5904\u7406\u6811\u5168\u4e3a\u767d\u70b9\u7684\u60c5\u51b5 
\t\t\t}
\t\t\tfor(int p=min(j,sz[v]);p;--p){
\t\t\t\tif(f[u][j-p]==-1)continue;
\t\t\t\tll val=(ll)e[i].w * p *(k-p)+(ll)e[i].w * (sz[v]-p) * (n-k-(sz[v]-p));
\t\t\t\tf[u][j]=max(f[u][j],f[u][j-p]+f[v][p]+val);
\t\t\t}
\t\t}
\t\t
\t}
//\tfor(int i=head[u];i;i=e[i].next ){
//\t\tint v=e[i].to ;
//\t\tif(v==fa)continue;
//\t\tfor(int j=min(sz[u],k);j>=0;j--)//\u6b64\u5904\u5012\u5e8f\u679a\u4e3e\u662f\u4e3a\u4e86\u907f\u514d\u91cd\u590d\u9009\u53d6
//\t\t\tfor(int p=0;p<=min(j,sz[v]);p++){
//\t\t\t\tif(f[u][j-p]>=0){
//\t\t\t\t\tll val=(ll)e[i].w * p *(k-p)+(ll)e[i].w * (sz[v]-p) * (n-k-(sz[v]-p));
//\t\t\t\t\tf[u][j]=max(f[u][j],f[u][j-p]+f[v][p]+val);
//\t\t\t\t}
//\t\t\t}
//\t}
}


int main(){
\tmemset(head,-1,sizeof(head));
\tn=read(),k=read();
\tif(n-k<k)k=n-k;
\tfor(int i=1;i<n;i++){
\t\tint fr=read(),to=read(),dis=read();
\t\tadd(fr,to,dis);
\t\tadd(to,fr,dis);
\t}
\tfor (int i = 0; i < 100000; i++)
\t    i--, i++, i--, i++, i--, i++;
\tdp(1,0);
\tcout<<f[1][k];
\treturn 0;
}