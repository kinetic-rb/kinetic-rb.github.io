#include <iostream>
#include <vector>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 1003, Hat_T = 1003;

struct Rs {
  tp w, c;

  Rs() = default;
  Rs(tp w, tp c) : w(w), c(c) {}
};

vector<Rs> mt[Hat_T];
tp f[Hat_N];

signed main() {
  tp m, n, t = 0;
  cin >> m >> n;
  for (tp i = 0; i < n; ++i) {
    tp w, c, p;
    cin >> w >> c >> p;
    if (mt[p].emplace_back(w, c); p > t) {
      t = p;
    }
  }
  for (tp i = 1; i <= t; ++i) {
    for (tp j = m; ~j; --j) {
      for (auto&& [w, c] : mt[i]) {
        if (w > j) {
          continue;
        }
        f[j] = max(f[j], f[j - w] + c);
      }
    }
  }
  cout << f[m];
  return 0;
}