#include <iostream>

using namespace std;
using vt = long long;

signed main(){
  vt n, k, s, ans = 1, mod, div;
  if (cin >> n >> k >> s; s < k || k * (n - 1) < s) {
    cout << "NO";
    return 0;
  }
  mod = s % k;
  div = s / k;
  cout << "YES
";
  for (vt i = 1; i <= mod; ++i) {
    cout << (ans = (i & 1 ? s / k + 2 : 1)) << ' ';
  }
  for (vt i = mod; i < k; ++i) {
    cout << (ans += (ans > div ? -1 : 1) * div) << ' ';
  }
  return 0;
}