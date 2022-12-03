#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pre(i,a,b) for(int i=a;i>=b;i--)
#define N 100005
using namespace std;
int n,k,a[N];
int main(){
  scanf("%d%d",&n,&k);k--;
  rep(i,1,n)scanf("%d",&a[i]);
  int ans = a[n] - a[1] + 1;
  rep(i,1,n)a[i] = a[i + 1] - a[i] - 1;
  sort(a+1,a+n);rep(i,1,k)ans -= a[n - i];
  printf("%d
",ans);return 0;
} 