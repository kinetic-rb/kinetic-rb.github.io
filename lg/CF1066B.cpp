#include <iostream>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 1003;

bool h[Hat_N];
tp n, r;

tp Calc() {
  tp c = 0, x = ~r + 2;
  for (tp y; x + r <= n; x = y, ++c) {
    y = min(x + (r << 1) - 1, n);
    while (y > 0 && !h[y]) {
      --y;
    }
    if (!y || x == y) {
      return -1;
    }
  }
  return c;
}

signed main() {
  cin >> n >> r;
  for (tp i = 1; i <= n; ++i) {
    cin >> h[i];
  }
  cout << Calc();
  return 0;
}