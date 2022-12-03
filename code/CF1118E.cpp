#include <iostream>

using namespace std;
using tp = int64_t;

signed main() {
  tp n, k;
  cin >> n >> k;
  if (n > k * (k - 1)) {
    puts("NO");
  } else {
    puts("YES");
    for (tp i = 1; i < k; ++i) {
      for (tp j = i + 1; j <= k && n > 0; ++j) {
        if (i != j) {
          if (n--) {
            cout << i << ' ' << j << '\n';
          }
          if (n--) {
            cout << j << ' ' << i << '\n';
          }
        }
      }
    }
  }
  return 0;
}