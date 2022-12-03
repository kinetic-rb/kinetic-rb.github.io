#include <iostream>

using namespace std;
using tp = intmax_t;
constexpr tp Hat_N = 103;

bool v[Hat_N];

signed main() {
  tp n, cnt = 0;
  cin >> n;
  for (tp i = 0; i < n; ++i) {
    cin >> v[i];
  }
  for (tp i = 2; i < n; ++i) {
    if (v[i] && !v[i - 1] && v[i - 2]) {
      ++cnt;
      v[i] = 0;
    }
  }
  cout << cnt;
  return 0;
}