#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;
using i64 = long long;

i64 k, b, n, x, y;

i64 num(i64 i) {
  return (i - x) * (i - x) + (k * i + b - y) * (k * i + b - y);
}

i64 fs() {
  i64 qloc = 1;
  for (i64 pew = 1 << 26; pew; pew >>= 1) {
    i64 l = qloc - pew, r = qloc + pew;
    if (l > 0 && num(l) <= num(qloc))
      qloc = l;
    if (r <= n && num(r) < num(qloc))
      qloc = r;
  }
  return qloc;
}

signed main() {
  ios_base::sync_with_stdio(false);
  i64 t;
  for (cin >> t; t--; cout << fs() << '\n') {
    cin >> k >> b >> n >> x >> y;
  }
  return 0;
}