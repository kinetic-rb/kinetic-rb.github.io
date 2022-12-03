#include <iostream>
#define M(i, j)    \
  ++cnt[s[i]];     \
  --cnt[s[i] = j]; \
  break
#define C(i, j)     \
  if (cnt[j] > 0) { \
    M(i, j);        \
  }

using namespace std;
using tp = int32_t;

tp cnt[3];
string s;

void P() {
  for (auto&& i : s) {
    i ^= 48;
  }
}

signed main() {
  tp n;
  cin >> n >> s;
  P();
  cnt[0] = cnt[1] = cnt[2] = n / 3;
  for (tp i = 0; i < n; ++i) {
    cnt[s[i]]--;
  }
  for (tp i = 0; i < n; ++i) {
    if (cnt[s[i]] < 0) {
      for (tp j = 0; j < s[i]; ++j) {
        C(i, j);
      }
    }
  }
  for (tp i = n - 1; ~i; --i) {
    if (cnt[s[i]] < 0) {
      for (tp j = 2; j > s[i]; --j) {
        C(i, j);
      }
    }
  }
  P();
  cout << s;
  return 0;
}