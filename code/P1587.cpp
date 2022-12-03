#include<map>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define fp(i,a,b) for(int i=a,I=b;i<=I;++i)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
using namespace std;
const int N=7e5+5,E=2e6+5;
typedef int arr[N];typedef long long ll;
struct Am{int nx,x,w;}e1[E];
struct Ans{int nx,n,m,k;ll w;}e2[E];
int n,m,k,M,c1,c2,K[2000],f1[E],f2[E];arr is,pr,mu,Smu;
int Sm(int x){
    if(x<=M)return Smu[x];
    int u=(x+2017)%E;
    for(int i=f1[u];i;i=e1[i].nx)if(e1[i].x==x)return e1[i].w;
    e1[++c1]=Am{f1[u],x,1};f1[u]=c1;
    int&w=e1[c1].w,i=2,j=sqrt(x);
    for(;i<=j;++i)w-=Sm(x/i);
    for(;i<=x;i=j+1)j=x/(x/i),w-=(j-i+1)*Sm(x/i);
    return w;
}
ll sol(int n,int m,int k){
    if(!n||!m)return 0;
    int u=(2017ll*n+m+k)%E;
    for(int i=f2[u];i;i=e2[i].nx)if(e2[i].n==n&&e2[i].m==m&&e2[i].k==k)return e2[i].w;
    e2[++c2]=Ans{f2[u],n,m,k,0};f2[u]=c2;ll&w=e2[c2].w;
    if(k==1){
        if(n>m)swap(n,m);
        int i=1,j=sqrt(n),s,t=0,x,y;
        for(;i<=j;++i,t=s)s=Sm(i),w+=1ll*(n/i)*(m/i)*(s-t);
        for(;i<=n;i=j+1,t=s)x=n/i,y=m/i,j=min(n/x,m/y),s=Sm(j),w+=1ll*x*y*(s-t);
        u=(2017ll*m+n+k)%E;e2[++c2]=Ans{f2[u],m,n,k,w};f2[u]=c2;
    }else for(int i=1;i<=K[0]&&K[i]<=k;++i)
            if(k%K[i]==0&&mu[K[i]])
                w+=sol(m/K[i],n,K[i])*mu[K[i]];
    return w;
}
int main(){
    #ifndef ONLINE_JUDGE
        file("s");
    #endif
    scanf("%d%d%d",&n,&m,&k);
    M=min(N-5,max(k,min(n,m)));Smu[1]=mu[1]=1;
    fp(i,2,M){
        if(!is[i])pr[++pr[0]]=i,mu[i]=-1;
        for(int j=1,x;j<=pr[0]&&(x=i*pr[j])<=M;++j){
            is[x]=1;if(i%pr[j])mu[x]=-mu[i];else break; 
        }Smu[i]=Smu[i-1]+mu[i];
    }
    fp(i,1,k)if(k%i==0)K[++K[0]]=i;
    printf("%lld",sol(n,m,k));
return 0;
}