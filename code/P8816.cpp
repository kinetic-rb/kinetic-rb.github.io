#include <algorithm>
#include <cmath>
#include <iostream>
#define ra __Read_int()

using namespace std;
using tp = long long;

tp __Read_int() {
  tp x;
  scanf("%lld", &x);
  return x;
}

constexpr tp Hat_N = 503, Hat_K = 103;

tp f[Hat_N][Hat_K];
pair<tp, tp> p[Hat_N];

signed main() {
  tp n = ra, m = ra, tar = m;
  for (tp i = 1; i <= n; ++i) {
    p[i].first = ra;
    p[i].second = ra;
  }
  stable_sort(p + 1, p + n + 1);
  for (tp i = 1; i <= n; ++i) f[i][0] = 1;
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 0; j < i; ++j) {
      for (tp k = 0; k <= m; ++k) {
        tp c = p[i].first - p[j].first + p[i].second - p[j].second - 1;
        if (p[j].second <= p[i].second && k - c >= 0) {
          f[i][k] = max(f[i][k], f[j][k - c] + c + 1);
        }
      }
    }
  }
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 0; j <= m; ++j) {
      tar = max(tar, f[i][j] + (m - j));
    }
  }
  printf("%lld
", tar);
  return 0;
}