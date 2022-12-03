#include <algorithm>
#include <iostream>

using namespace std;
using tp = int64_t;
constexpr tp Hvt_N = 2e5 + 3;
tp n, m, v[Hvt_N];

bool check(tp x) {
  tp k = 0, sum = 0, cnt = 0;
  for (tp i = 0; i < n; ++i) {
    ++k;
    sum += max(v[i] - cnt, 0ll);
    if (k >= x) {
      k = 0;
      ++cnt;
    }
  }
  return sum < m;
}

tp fs() {
  tp qloc = 0;
  for (tp loc = 1ll << 61; loc; loc >>= 1) {
    if (check(qloc + loc)) {
      qloc += loc;
    }
  }
  return qloc;
}

signed main() {
  tp r;
  cin >> n >> m;
  for (tp i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v, v + n);
  reverse(v, v + n);
  r = fs() + 1;
  cout << (r == 4611686018427387904 ? -1 : r);
  return 0;
}