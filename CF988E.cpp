#include <iostream>

using namespace std;
using dt = long long;

static dt calc(dt i, dt j, dt k, dt n) {
  return (n << 1) - 3 - j - i + (j < i) + k - (i < k) - (j < k);
}

signed main() {
  string s;
  dt n, M = 0x7fffffffffffffff;
  cin >> s;
  n = s.size();
  if (n < 3) {
    dt x = atoll(s.c_str());
    if (x % 25) {
      x = (x % 10) * 10 + x / 10;
      cout << (x % 25 ? -1 : 1);
      return 0;
    } else {
      cout << 0;
      return 0;
    }
  }
  for (dt i = 0; i < n; ++i) {
    for (dt j = 0; j < n; ++j) {
      if (i != j) {
        for (dt k = 0; k < n; ++k) {
          if (j != k && i != k && !(((s[i] ^ 48) * 10 + (s[j] ^ 48)) % 25) &&
              s[k] ^ 48 && calc(i, j, k, n) < M) {
            M = calc(i, j, k, n);
          }
        }
      }
    }
  }
  cout << (M == 0x7fffffffffffffff ? -1 : M);
  return 0;
}