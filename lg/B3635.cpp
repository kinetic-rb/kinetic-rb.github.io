#include <iostream>
#include <vector>

using namespace std;
using tp = long long;

signed main() {
  tp n;
  scanf("%lld", &n);
  vector<tp> f(n + 1, -1ull / 2);
  f[0] = 0;
  for (tp i = 1; i <= n; ++i) {
    f[i] = min(f[i], f[i - 1] + 1);
    if (i >= 5) {
      f[i] = min(f[i], f[i - 5] + 1);
    }
    if (i >= 11) {
      f[i] = min(f[i], f[i - 11] + 1);
    }
  }
  cout << f[n];
  return 0;
}