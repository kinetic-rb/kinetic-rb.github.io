#include <iostream>
#include <vector>

using namespace std;
using tp = long long;

signed main() {
  tp n;
  scanf("%lld", &n);
  vector<tp> f(n + 1, -1ull / 2);
  f[1] = 0;
  for (tp i = 2; i <= n; ++i) {
    f[i] = f[i - 1] + 1;
    if (~i & 1) {
      f[i] = min(f[i], f[i >> 1] + 1);
    }
  }
  cout << f[n];
  return 0;
}