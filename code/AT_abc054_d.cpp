#include <iostream>
#include <vector>

using namespace std;
using tp = long long;

signed main() {
  tp n, ba, bb, MIN = -1ull / 2;
  cin >> n >> ba >> bb;
  vector<tp> a(n), b(n), c(n);
  vector<vector<tp>> f(403, vector<tp>(403, -1ull / 2));
  f[0][0] = 0;
  for (tp i = 0; i < n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }
  for (tp i = 0; i < n; ++i) {
    for (tp j = 400; j >= a[i]; --j) {
      for (tp k = 400; k >= b[i]; --k) {
        if (f[j - a[i]][k - b[i]] != -1ull / 2) {
          f[j][k] = min(f[j][k], f[j - a[i]][k - b[i]] + c[i]);
        }
      }
    }
  }
  for (tp i = 1; i * max(ba, bb) <= 400; ++i) {
    MIN = min(MIN, f[i * ba][i * bb]);
  }
  cout << (MIN == -1ull / 2 ? -1 : MIN);
  return 0;
} 