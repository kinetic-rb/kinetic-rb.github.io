#include <algorithm>
#include <iostream>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 100'003;

struct Rs {
  tp q, p;

  Rs() = default;
  bool operator<(const Rs& comp) const { return p < comp.p; }
} k[Hat_N];
tp ml[Hat_N], z[Hat_N];

signed main() {
  tp n, m, r, MAX = 0;
  cin >> n >> m >> r;
  for (tp i = 0; i != n; ++i) {
    cin >> ml[i];
  }
  for (tp i = 0; i != m; ++i) {
    cin >> k[i].q >> k[i].p;
  }
  for (tp i = 0; i != r; ++i) {
    cin >> z[i];
  }
  stable_sort(ml, ml + n);
  stable_sort(k, k + m);
  stable_sort(z, z + max(n, r));
  reverse(z, z + max(n, r));
  for (tp i = 0; i != n; ++i) {
    MAX += z[i];
  }
  for (tp i = n - 1, j = m - 1; ~i; --i) {
    static tp temp = 0, sum = MAX;
    sum -= z[i];
    for (tp q = ml[i]; q && ~j; j -= !k[j].q) {
      tp p = min(q, k[j].q);
      q -= p;
      k[j].q -= p;
      temp += p * k[j].p;
    }
    MAX = max(MAX, sum + temp);
  }
  cout << MAX;
  return 0;
}