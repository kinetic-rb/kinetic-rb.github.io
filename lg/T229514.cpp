#include <algorithm>
#include <iostream>

using namespace std;
using tp = long long;
const tp Hat_N = 1e3 + 3;

tp tar[Hat_N], md, d[Hat_N];

bool Crt(tp dep, tp x, tp y) {
  bool f = 0;
  if (dep > md) {
    if (x) {
      return 0;
    }
    if (tar[md] > d[md]) {
      for (tp i = 1; i <= md; ++i) {
        tar[i] = d[i];
      }
    }
    return 1;
  }
  for (tp i = max((y + x - 1) / x, d[dep - 1] + 1);
       i <= ((y + x - 1) / x) * (md - dep + 1); ++i) {
    d[dep] = i;
    tp dx = x * i - y, dy = y * i, g = __gcd(dx, dy);
    f |= Crt(dep + 1, dx / g, dy / g);
  }
  return f;
}

signed main() {
  tp a, b;
  cin >> a >> b;
  for (md = 1;; ++md) {
    tar[md] = 0x3f3f3f3f;
    if (Crt(1, a, b)) {
      for (tp i = 1; i <= md; ++i) {
        cout << tar[i] << ' ';
      }
      break;
    }
  }
  return 0;
}