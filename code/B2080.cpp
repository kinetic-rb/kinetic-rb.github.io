#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l,END##i=r;i<=END##i;++i)
#define dn(r,l,i) for(int i=r,END##i=l;i>=END##i;--i)
using namespace std;
typedef long long i64;
const int INF =2147483647;
double x,r; int n;
int main(){
    scanf("%lf%d",&x,&n); up(0,n,i) r=1+x*r;
    printf("%.2lf
",r);
    return 0;
}