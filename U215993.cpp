#include <iostream>

using namespace std;
using vt = long long;
constexpr vt Hat_N = 200003;

vt num[Hat_N], ps[Hat_N];

void Lit(vt n) {
  vt m, p;
  cin >> m >> p;
  for (vt i = 1; i <= n; ++i) {
    cin >> num[i];
    num[i] %= p;
  }
  while (m--) {
    vt op, l, r;
    cin >> op >> l >> r;
    if (op == 1) {
      vt x;
      cin >> x;
      for (vt i = l; i <= r; ++i) {
        num[i] = (num[i] + x) % p;
      }
    } else {
      vt cnt = 0;
      for (vt i = l; i <= r; ++i) {
        if (!num[i]) {
          ++cnt;
        }
      }
      cout << cnt << '\n';
    }
  }
}

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  vt n, m, p;
  cin >> n;
  if (n <= 1000) {
    Lit(n);
    return 0;
  }
  cin >> m >> p;
  for (vt i = 1; i <= n; ++i) {
    cin >> num[i];
    ps[i] = ps[i - 1] + !(num[i] % p);
  }
  while (m--) {
    vt l, r;
    char c;
    cin >> c >> l >> r;
    cout << ps[r] - ps[l - 1] << '\n';
  }
  return 0;
}