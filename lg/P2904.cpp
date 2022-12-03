#include <iostream>
#include <vector>

using namespace std;
using tp = long long;

signed main() {
  tp n, m;
  scanf("%lld%lld", &n, &m);
  vector<tp> v(n + 1, 0), f(n + 1, -1ull / 4);
  f[0] = 0;
  for (tp i = 1; i <= n; ++i) {
    scanf("%lld", &v[i]);
    v[i] += v[i - 1];
  }
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 0; j < i; ++j) {
      f[i] = min(f[i], f[j] + m + m + v[i - j]);
    }
  }
  cout << f[n] - m;
  return 0;
}