#include <iostream>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 40003;

tp f[Hat_N], c[Hat_N], w[Hat_N], v[Hat_N];
tp n;

void dp01(tp W, tp C) {
  for (tp i = n; i >= W; --i) {
    f[i] = max(f[i], f[i - W] + C);
  }
  return;
}

tp Calc(tp x) {
  tp i = 62;
  while (1) {
    if (x & (1ll << i)) {
      return i;
    }
    --i;
  }
}

signed main() {
  tp m;
  cin >> m >> n;
  for (tp i = 0; i < m; ++i) {
    cin >> c[i] >> w[i] >> v[i];
  }
  for (tp i = 0; i < m; ++i) {
    tp x = Calc(v[i]);
    for (tp j = 0; j < x; ++j) {
      dp01((1 << j) * w[i], (1 << j) * c[i]);
    }
    v[i] -= (1 << x) - 1;
    dp01(v[i] * w[i], v[i] * c[i]);
  }
  cout << f[n];
  return 0;
}