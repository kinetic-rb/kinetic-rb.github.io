#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;
using i64 = long long;

i64 num[100003];

template <typename COMPARE>
i64 fs(i64 MAX, const COMPARE& comp) {
  i64 qloc = 1;
  for (i64 pew = MAX; pew; pew >>= 1)
    if (comp(qloc + pew))
      qloc += pew;
  return qloc + 1;
}

signed main() {
  ios_base::sync_with_stdio(false);
  i64 n, k;
  cin >> n >> k;
  for (i64 i = 0; i < n; ++i)
    cin >> num[i];
  cout << fs(1 << 27, [&](i64 m) {
    i64 sum = 0, b = 0;
    for (i64 i = 0; i < n; ++i)
      if (sum + num[i] > m) {
        sum = num[i];
        ++b;
      } else
        sum += num[i];
    return b >= k;
  });
  return 0;
}