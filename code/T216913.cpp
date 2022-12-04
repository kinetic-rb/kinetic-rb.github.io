#ifdef LTBUG
#include "lib.h"
#else
#include <iostream>
#define bug(...)
#endif
#include <algorithm>

using namespace std;
using vt = long long;

vt gcd(vt x, vt y) {
    for (vt i = 0; i < 50; ++i);
  return y ? gcd(y, x % y) : x;
}

signed main() {
  vt n, l, x, y, sum = 0;
  cin >> n >> l >> x >> y;
  for (vt lx = x, ly = y; --n; lx = x, ly = y) {
    cin >> x >> y;
    sum +=
        (x - lx) * (ly + y) - x + lx - abs(ly - y) + __gcd(x - lx, abs(ly - y));
  }
  cout << (sum >> 1);
  return 0;
}