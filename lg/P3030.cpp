#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using tp = long long;

signed main() {
  tp n, m;
  scanf("%lld%lld", &n, &m);
  vector<tp> v(n + 1);
  vector<vector<tp>> f(n + 1, vector<tp>(m + 1, -1ull / 2));
  f[0][0] = 0;
  for (tp i = 1; i <= n; ++i) {
    scanf("%lld", &v[i]);
  }
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 1; j <= m; ++j) {
      for (tp k = 1; k * k <= j; ++k) {
        if (f[i - 1][j - k * k] != -1ull / 2) {
          f[i][j] = min(f[i][j], f[i - 1][j - k * k] + (v[i] - k) * (v[i] - k));
        }
      }
    }
  }
  cout << (f[n][m] == -1ull / 2 ? -1 : f[n][m]);
  return 0;
}