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
  vt n, l, x, y;
  __int128 sum = 0;
  string res = "";
  cin >> n >> l >> x >> y;
  for (vt lx = x, ly = y; --n; lx = x, ly = y) {
    cin >> x >> y;
    sum +=
        (x - lx) * (ly + y) - x + lx - abs(ly - y) + __gcd(x - lx, abs(ly - y));
  }
  for (sum >>= 1; sum; sum /= 10) {
    res.push_back((sum % 10) ^ 48);
  }
  reverse(res.begin(), res.end());
  cout << res;
  return 0;
}