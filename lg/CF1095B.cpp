#include <algorithm>
#include <iostream>

using namespace std;
using tp = int_fast32_t;
constexpr tp Hat_N = 100003;

tp val[Hat_N];

signed main() {
  tp n;
  cin >> n;
  for (tp i = 0; i < n; ++i) {
    cin >> val[i];
  }
  stable_sort(val, val + n);
  cout << min(val[n - 2] - *val, val[n - 1] - val[1]);
  return 0;
}