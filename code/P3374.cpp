#include <cstdint>
#include <iostream>

using namespace std;
using tp = int64_t;
constexpr tp Hat_N = 5e5 + 3;

tp rec[Hat_N];
tp n;

tp lowbit(tp x) {
  return x & -x;
}

void modify(tp loc, tp k) {
  while (loc <= n) {
    rec[loc] += k;
    loc += lowbit(loc);
  }
}

tp query(tp loc) {
  tp tar = 0;
  while (loc) {
    tar += rec[loc];
    loc -= lowbit(loc);
  }
  return tar;
}

tp query(tp l, tp r) {
  return query(r) - query(l - 1);
}

signed main() {
  tp m;
  cin >> n >> m;
  for (tp i = 1; i <= n; ++i) {
    tp x;
    cin >> x;
    modify(i, x);
  }
  while (m--) {
    tp op, x, y;
    cin >> op >> x >> y;
    if (op == 1) {
      modify(x, y);
    } else {
      cout << query(x, y) << '\n';
    }
  }
  return 0;
}