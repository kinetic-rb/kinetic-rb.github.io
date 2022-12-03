#include <iostream>

using namespace std;
using tp = intmax_t;

signed main() {
  tp t;
  cin >> t;
  while (t--) {
    tp a, b, k;
    cin >> a >> b >> k;
    cout << (k >> 1) * (a - b) + (k & 1) * a << '\n';
  }
  return 0;
}