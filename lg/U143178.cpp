#include <algorithm>
#include <bitset>
#include <cstdint>
#include <iostream>
#include <numeric>

using namespace std;
using tp = int64_t;
constexpr tp Hat_N = 2003;

bitset<Hat_N> h[Hat_N];

signed main() {
  tp n, tar = 0;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 1; j <= n; ++j) {
      char c;
      cin >> c;
      h[i][j] = c & 15;
    }
    h[i][i] = 1;
  }
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 1; j <= n; ++j) {
      if (h[j][i]) {
        h[j] |= h[i];
      }
    }
  }
  for_each(h + 1, h + n + 1, [&tar](auto&& x) { tar += x.count(); });
  cout << tar;
  return 0;
}