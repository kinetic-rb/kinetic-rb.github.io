#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l,END##i=r;i<=END##i;++i)
#define dn(r,l,i) for(int i=r,END##i=l;i>=END##i;--i)
using namespace std;
typedef long long i64;
const int INF =2147483647;
int n,s,x;
int main(){
    scanf("%d",&n); up(1,n,i){scanf("%d",&x);s+=x;}
    printf("%d %.5lf
",s,1.0*s/n);
    return 0;
}