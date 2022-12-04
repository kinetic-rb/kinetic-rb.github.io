#include <iostream>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 1000003, Mod = 1000000007;
tp e[Hat_N];

signed main () {
  tp n, h = 1, t = 0;
  cin >> n;
  while (n--) {
    char op;
    tp k;
    cin >> op >> k;
    if (op == 'I') {
      tp x, y, now = 1;
      cin >> x >> y;
      while (k--) {
        e[t = (t + 1) % Hat_N] = now = (now * x + y) % Mod;
      }
    } else if (op == 'D') {
      h = (h + k) % Hat_N;
    } else {
      cout << e[(h + k) % Hat_N] << ' ';
    }
  }
  return 0;
}