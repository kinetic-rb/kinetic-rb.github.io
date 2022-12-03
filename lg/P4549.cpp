#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;
using tp = int64_t;

signed main() {
  tp n, tar;
  cin >> n >> tar;
  while (--n) {
    tp x;
    cin >> x;
    tar = __gcd(tar, abs(x));
  }
  cout << tar;
  return 0;
}