#include <iostream>

using namespace std;
using tp = int;
constexpr tp Hat_N = 5e3 + 3, Hat_M = 5e5 + 3;

tp h[Hat_N], t[Hat_N], v[Hat_N];

struct CE {
  tp n, x;
} c[Hat_M];

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tp n, m, l = 0;
  cin >> n >> m;
  while (m--) {
    tp x;
    cin >> x >> c[++l].x;
    if (!h[x]) {
      h[x] = l;
    }
    c[t[x]].n = l;
    t[x] = l; 
  }
  for (tp i = 1; i < n; ++i) {
    tp x, y;
    cin >> x >> y;
    if (h[x]) {
      c[t[x]].n = h[y];
      t[x] = t[y];
      v[y] = 1;
    }
  }
  for (tp i = 1; i <= n; ++i) {
    if (!v[i]) {
      for (tp j = h[i]; j; j = c[j].n) {
        cout << c[j].x << ' ';
      }
      break;
    }
  }
  return 0;
}