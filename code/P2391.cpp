#include <iostream>

using namespace std;
using tp = int;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tp n, m, p, q;
  cin >> n >> m >> p >> q;
  for (tp i = 1; i <= n; i++)
    for (tp j = m; j > -1; j--) {
      tp c1 = (j * p + q) % n + 1, c2 = (j * q + p) % n + 1;
      if (c1 > c2)
        c1 ^= c2 ^= c1 ^= c2;
      if ((c1 <= i && c2 >= i) || !j) {
        cout << j << '\n';
        break;
      }
    }
    return 0;
}