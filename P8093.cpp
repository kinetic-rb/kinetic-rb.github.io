#include <iostream>

using namespace std;
using tp = long long;

tp solve() {
  tp s, e, l, MIN = 0x7fffffffffffffff, _s;
  if (cin >> s >> e; (_s = s) == e) {
    return 0;
  }
  for (l = 63; ~l; --l) {
    if ((e >> l) & 1) {
      ++l;
      break;
    }
  }
  for (tp i = 1; i <= l; ++i) {
    tp cnt = 0, x = e >> (l - i);
    while (s ^ x) {
      if (s > x) {
        if (s & 1) {
          ++s;
        } else {
          s >>= 1;
        }
        ++cnt;
      } else {
        cnt += x - s;
        s = x;
      }
    }
    for (tp j = i + 1; j <= l; ++j) {
      s <<= 1;
      ++cnt;
      if (e >> (l - j) != s) {
        ++s;
        ++cnt;
      }
    }
    if (s = _s; cnt < MIN) {
      MIN = cnt;
    }
  }
  return MIN;
}

signed main() {
  tp t;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }
  return 0;
}