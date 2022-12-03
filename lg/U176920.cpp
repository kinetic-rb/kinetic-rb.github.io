#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int n,d;
ll sum=1;
inline int read(){
    ll x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}inline void write(ll x){
    if(x<0)x=-x,putchar('-');
    if(x>9)write(x/10);
    putchar(x%10+'0');
}int main(){
    n=read();d=read();
    write( (1ll+(1ll+(n-1ll)*d))*n/2ll );puts("");
    return 0;
} 