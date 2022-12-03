#include <algorithm>
#include <iostream>
using namespace std;
const int N  = 1e5 + 5;
int n,t,a[N],ans;
int main(){
  ios::sync_with_stdio(false);
  cin >> n >> t;
  for(int i = 1;i <= n;++i){
      static int* ap = a;
    cin >> *++ap;
  }
  stable_sort(a + 1,a + n + 1);
  for(int res = 0;res + a[ans + 1] <= t && ans < n;res += a[++ans]){
  }
  cout << ans;
  return 0;
}