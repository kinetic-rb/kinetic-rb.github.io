#include <cstring>
#include <iostream>

using namespace std;
using dt = long long;
constexpr dt HAT_T = 103, HAT_N = 103, HAT_M = 10003;

dt p[HAT_T][HAT_N], f[HAT_M];

signed main() {
  ios_base::sync_with_stdio(false);
  dt t, n, m, res;
  cin >> t >> n >> m;
  res = m;
  for (dt i = 1; i <= t; ++i) {
    for (dt j = 1; j <= n; ++j) {
      cin >> p[i][j];
    }
  }
  //------------------------------------// \u8bfb\u5165
  for (dt i = 1; i < t; ++i) {  // \u5929
    dt MAX = 0;
    memset(f, -0x7f, sizeof f);
    f[res] = res;  // \u4ec0\u4e48\u90fd\u4e0d\u505a\u7684\u6536\u76ca
    //---------------------------------------// \u521d\u59cb\u5316
    for (dt j = 1; j <= n; ++j) {            // \u7269\u54c1
      for (dt k = res; k >= p[i][j]; --k) {  // \u6709\u591a\u5c11\u6536\u76ca
        if (f[k] + p[i + 1][j] - p[i][j] >
            f[k - p[i][j]]) {  // \u53ef\u4ee5\u83b7\u5f97\u66f4\u591a\u7684\u6536\u76ca
          f[k - p[i][j]] = f[k] + p[i + 1][j] - p[i][j];  // \u66f4\u65b0
        }
      }
    }
    for (dt j = 0; j <= res; ++j) {
      if (f[j] > MAX) {
        MAX = f[j];
      }
    }
    res = MAX;
    //----------------------------------// \u5bfb\u627e\u6700\u4f18\u72b6\u6001
  }
  cout << res;
  return 0;
}