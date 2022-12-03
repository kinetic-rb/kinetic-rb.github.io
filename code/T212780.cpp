#include <iostream>

using namespace std;
using dt = long long;

dt num[303][303];
dt f;

struct loc {
  dt x, y;

  loc() : x(0), y(0) {}
  loc(dt x, dt y) : x(x), y(y) {}
} res;

ostream& operator<<(ostream& out, const loc& x) {
  out << x.x << ' ' << x.y << '\n';
  return out;
}

bool fs(dt x1, dt x2, dt y1, dt y2) {
  if (x1 > x2 || y1 > y2)
    return false;
  dt x = x1 + x2 >> 1, y = y1 + y2 >> 1;
  if (num[x][y] == f) {
    if (!fs(x1, x - 1, y1, y2))
      res = loc(x, y);
    return true;
  }
  if (num[x][y] < f)
    return fs(x1, x, y + 1, y2) || fs(x + 1, x2, y1, y2);
  return fs(x1, x - 1, y1, y2) || fs(x, x2, y1, y - 1);
}

signed main() {
  ios_base::sync_with_stdio(false);
  dt n, m, t;
  cin >> n >> m >> t;
  for (dt i = 1; i <= n; ++i)
    for (dt j = 1; j <= m; ++j)
      cin >> num[i][j];
  while (t--) {
    res = loc();
    cin >> f;
    fs(1, n, 1, m);
    cout << res;
  }
  return 0;
}