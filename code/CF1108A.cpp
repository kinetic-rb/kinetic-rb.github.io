#include <iostream>

using namespace std;
using tp = int64_t;

signed main() {
  tp t;
  cin >> t;
  while (t--) {
    tp l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    cout << l1 << ' ' << (l1 != r2 ? r2 : l2) << '\n';
  }
  return 0;
}