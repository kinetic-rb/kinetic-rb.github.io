#include <iostream>
#include <cstring>
#include <map>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n,a[N],dp[N],res,l,r;
map<ll,ll> b;
int main(){
  cin >> n;
  for(int i = 1;i <= n;i++){
    cin >> a[i];
    if(b[a[i] - 1] < i){
      dp[i] = dp[b[a[i] - 1]] + 1;
    } else{
      dp[i] = 1;
    }
    b[a[i]] = i;
  }
  for(int i = 1;i <= n;i++){
    if(dp[i] > res){
      res = dp[i];
      r = a[i];
    }
  }
  cout << res << endl;
  l = r - res + 1;
  for(int i = 1;i <= n;i++){
    if(a[i] == l){
      cout << i << ' ';
      l++;
    }
  }
  return 0;
}