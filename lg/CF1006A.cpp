#include <iostream>

using namespace std;
using dt = long long;

signed main() {
  dt n;
  cin >> n;
  for (dt i = 1; i <= n; ++i) {
    dt x;
    cin >> x;
    cout << x - !(x & 1) << ' ';
  }
  return 0;
}