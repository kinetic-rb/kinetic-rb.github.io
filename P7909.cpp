#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  bool f=0;
  int r,l,ren,i;
  cin>>ren>>l>>r;
  int chu=r/ren;
  for(i=1;i<ren;i++){
    if(chu*ren-i>=l){
      f=1;
      break;
    }
    if(chu*ren+i>r) break;
  }
  if(f) cout<<ren-i;
  else cout<<i-1;
  return 0;
}
