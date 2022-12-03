#include <iostream>

using namespace std;
using tp = int_fast64_t;

signed main() {
  tp n, k;
  cin >> n >> k;
  cout << ((n * n - 1) % 998244353 * k + 1) % 998244353;
  return 0;
}