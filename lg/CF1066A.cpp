#include <iostream>

using namespace std;
using tp = long long;

signed main() {
  tp t;
  cin >> t;
  for (tp L, v, l, r; t--; cout << L / v + (l - 1) / v - r / v << '\n') {
    cin >> L >> v >> l >> r;
  }
  return 0;
}