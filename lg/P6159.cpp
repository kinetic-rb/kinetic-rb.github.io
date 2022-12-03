#include <iostream>

using namespace std;
using tp = uint64_t;

signed main() {
  tp n, m, k;
  cin >> n >> m >> k;
  cout << (k * m) % n;
  return 0;
}