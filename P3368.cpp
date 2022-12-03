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
  basic_ios<char, char_traits<char>>::sync_with_stdio(0);
  tp m;
  cin >> n >> m;
  for (tp i = 1; i <= n; ++i) {
    static tp last = 0;
    tp x;
    cin >> x;
    update(i, x - last);
    last = x;
  }
  while (m--) {
    tp op;
    cin >> op;
    if (op == 1) {
      tp l, r, k;
      cin >> l >> r >> k;
      update(l, k);
      update(r + 1, -k);
    } else {
      tp loc;
      cin >> loc;
      cout << query(loc) << '\n';
    }
  }
  return 0;
}