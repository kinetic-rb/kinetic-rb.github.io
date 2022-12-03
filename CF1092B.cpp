#include <algorithm>
#include <iostream>

using namespace std;
using tp = int32_t;
constexpr tp Hat_N = 103;

tp v[Hat_N];

signed main() {
  tp n, cnt = 0;
  cin >> n;
  for (tp i = 0; i < n; ++i) {
    cin >> v[i];
  }
  stable_sort(v, v + n);
  for (tp i = 0; i < n; ++ ++i) {
    cnt += v[i + 1] - v[i];
  }
  cout << cnt;
  return 0;
}