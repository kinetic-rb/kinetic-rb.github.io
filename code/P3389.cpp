#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace std;
using tp = long long;
constexpr bool __TEST_CASES__ = 0;
constexpr tp Hat_N = 103;

double v[Hat_N][Hat_N];

signed __PRE__() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(2);
  return 0;
}

signed __CORE__() {
  tp n;
  cin >> n;
  for_each(v, v + n,
           [&](auto& x) { for_each(x, x + n + 1, [](auto& y) { cin >> y; }); });
  for (tp i = 0; i < n; ++i) {
    tp loc = i;
    for (tp j = i + 1; j < n; ++j) {
      if (abs(v[j][i]) > abs(v[loc][i])) {
        loc = i;
      }
    }
    for (tp j = 0; j <= n; ++j) {
      swap(v[i][j], v[loc][j]);
    }
    if (!v[i][i]) {
      puts("No Solution");
      return 0;
    }
    for (tp j = 0; j < n; ++j) {
      if (i != j) {
        double p = v[j][i] / v[i][i];
        for (tp k = i + 1; k <= n; ++k) {
          v[j][k] -= v[i][k] * p;
        }
      }
    }
  }
  for (tp i = 0; i < n; ++i) {
    cout << v[i][n] / v[i][i] << '\n';
  }
  return 0;
}

signed main() {
  static bool __NOT_READED__ = 1;
  static tp __TEST_COUNT__ = 1;
  if (__NOT_READED__) {
    if (__PRE__()) {
      return -1;
    }
    if (__TEST_CASES__) {
      cin >> __TEST_COUNT__;
    }
    __NOT_READED__ = 0;
  }
  if (__TEST_COUNT__-- && (main() || __CORE__())) {
    return -1;
  }
  return 0;
}