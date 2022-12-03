#include <iostream>

using namespace std;
using tp = long long;

signed main() {
  tp n;
  cin >> n;
  while (n--) {
    tp x;
    cin >> x;
    while (!(x & 1)) {
      x >>= 1;
    }
    if (!(x % 3)) {
      x /= 3;
    }
    cout << (x != 1) << '\n';
  }
  return 0;
}