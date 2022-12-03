#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define reg register
#define ll long long
#define p 1000000000
#define phi 400000000
using namespace std;

int table[8] = {0,0,0,0,24,480,7680,107520};
int pw1[32769],pw2[32769],pw3[32769],pw4[32769];

inline int solve(const int& n){
    reg int x = (ll)pw1[n&32767]*pw2[n>>15]%p,y = (ll)x*x%p;
    reg int res = (81ll*pw3[n&32767]%p*pw4[n>>15]%p-64ll*x%p*y)%p;
    res = (res+6ll*y+p)%p;
    return (n&1)?(res<y?res-y+p:res-y):(res+y>=p?res+y-p:res+y);
}

int main(){
    pw1[0] = pw2[0] = pw3[0] = pw4[0] = 1;
    pw1[1] = 2;
    for(reg int i=2;i<=32768;++i) pw1[i] = pw1[i-1]<500000000?(pw1[i-1]<<1):(pw1[i-1]<<1)-p;
    pw2[1] = pw1[32768];
    for(reg int i=2;i<=32768;++i) pw2[i] = (ll)pw2[i-1]*pw2[1]%p;
    pw3[1] = 12;
    for(reg int i=2;i<=32768;++i) pw3[i] = (ll)pw3[i-1]*12%p;
    pw4[1] = pw3[32768];
    for(reg int i=2;i<=32768;++i) pw4[i] = (ll)pw4[i-1]*pw4[1]%p;
    reg ll n;
    reg int x;
    while(cin>>n){
    \tif(n==0) break;
        x = n>=phi?n%phi+phi:n;
        printf("%d
",x<8?table[x]:solve(x-4));
    }
}