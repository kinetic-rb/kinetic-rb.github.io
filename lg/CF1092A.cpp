#include <iostream>

using namespace std;
using tp = int32_t;

signed main() {
  tp t;
  cin >> t;
  while (t--) {
    tp n, k;
    cin >> n >> k;
    for (tp i = 1; i <= n; ++i) {
      putchar(i % k + 'a');
    }
    cout << '\n';
  }
  return 0;
}