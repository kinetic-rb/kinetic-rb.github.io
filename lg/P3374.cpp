#include <iostream>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 500003;

tp rec[Hat_N];
tp n;

tp lowbit(tp x) {
  return x & (~x + 1);
}

void update(tp x, tp k) {
  while (x <= n) {
    rec[x] += k;
    x += lowbit(x);
  }
}

tp query(tp x) {
  tp sum = 0;
  while (x) {
    sum += rec[x];
    x -= lowbit(x);
  }
  return sum;
}

signed main() {
  tp m;
  cin >> n >> m;
  for (tp i = 1; i <= n; ++i) {
    tp x;
    cin >> x;
    update(i, x);
  }
  while (m--) {
    tp op, x, y;
    cin >> op >> x >> y;
    if (op == 1) {
      update(x, y);
    } else {
      cout << query(y) - query(x - 1) << '\n';
    }
  }
  return 0;
}