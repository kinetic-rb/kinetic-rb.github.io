#include <cstdint>
#include <iostream>

using namespace std;
using tp = int64_t;
constexpr tp Hat_S = 23;

tp cnt[10], w[Hat_S], v[Hat_S];

void W(tp pw) {
  tp n, p = 0;
  string s;
  cin >> s;
  n = s.size();
  v[n] = 0, w[n] = 1;
  for (tp i = n - 1; ~i; --i) {
    s[i] &= 15;
    w[i] = w[i + 1] * 10;
    v[i] = v[i + 1] + w[i + 1] * s[i];
  }
  for (tp i = 0; i < n; ++i) {
    cnt[s[i]] += pw == -1;
    for (tp x = 0; x < s[i]; ++x) {
      cnt[x] += (p + (x > 0)) * w[i + 1] * pw;
    }
    cnt[s[i]] += ((p - (s[i] <= 0)) * w[i + 1] + v[i + 1] + 1) * pw;
    for (tp x = s[i] + 1; x <= 9; ++x) {
      cnt[x] += p * w[i + 1] * pw;
    }
    p = p * 10 + s[i];
  }
}

signed main() {
  W(-1);
  W(1);
  for (tp i = 0; i <= 9; ++i) {
    cout << cnt[i] << ' ';
  }
  return 0;
}