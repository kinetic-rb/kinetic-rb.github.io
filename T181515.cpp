#include<bits/stdc++.h>
using namespace std;

const int N=30,M=35;
int n,a[N],m,x[M],y[M],tot=1;
int main(){
  cin>>n>>m;
  for(int i=1;i<=m;i++)cin>>x[i]>>y[i];
  a[0]=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(x[tot]==i&&y[tot]==j){
        a[j]=0;
        tot++;
        continue;
      }else a[j]+=a[j-1];
    }
    a[0]=0;
  }
  cout<<a[n];
  return 0;
}