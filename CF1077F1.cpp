#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
using tp = int64_t;
constexpr tp Hat_S = 203;

tp val[Hat_S], f[Hat_S][Hat_S];

signed main() {
  tp n, k, x, target = -1145141919810;
  cin >> n >> k >> x;
  if (n / k > x) {
    cout << -1;
    return 0;
  }
  memset(f, -0x7f, sizeof f);
  **f = 0;
  for (tp i = 1; i <= n; ++i) {
    cin >> val[i];
  }
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 0; j < x; ++j) {
      f[i][j + 1] =
          (*max_element(f + max(0ll, i - k), f + i,
                        [j](tp* x, tp* y) { return x[j] < y[j]; }))[j] +
          val[i];
    }
  }
  for (tp i = n - k + 1; i <= n; ++i) {
    target = max(target, f[i][x]);
  }
  cout << target;
  return 0;
}