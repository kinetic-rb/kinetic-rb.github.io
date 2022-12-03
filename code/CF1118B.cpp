#include <iostream>

using namespace std;
using tp = int64_t;
constexpr tp Hat_N = 2e5 + 3;

tp v[Hat_N];

void Core() {
  tp n, Pre0 = 0, Pre1 = 0, Suf0 = 0, Suf1 = 0, cnt = 0;
  cin >> n;
  for (tp i = 1; i <= n; ++i) {
    cin >> v[i];
    (i & 1 ? Pre1 : Pre0) += v[i];
  }
  for (tp i = 1; i <= n; ++i) {
    (i & 1 ? Pre1 : Pre0) -= v[i];
    cnt += (Pre1 + Suf0 == Pre0 + Suf1);
    (i & 1 ? Suf1 : Suf0) += v[i];
  }
  cout << cnt << '\n';
}

signed main() {
  tp __Tests__ = 1;
  // cin >> __Tests__;
  while (__Tests__--) {
    Core();
  }
  return 0;
}