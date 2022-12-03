#include <iostream>

using namespace std;
using vt = long long;
constexpr vt Hat_N = 10000003, Mod = 1000000007;

vt num[Hat_N];

vt quick_sort(vt l, vt r, vt k) {
  if (l >= r) {
    return num[l];
  }
  vt i = l, j = r, x = num[l + r >> 1];
  while (i < j) {
    while (num[i] < x) {
      ++i;
    }
    while (num[j] > x) {
      --j;
    }
    if (i < j) {
      swap(num[i], num[j]);
    }
  }
  return (k <= j - l + 1 ? quick_sort(l, j, k) : quick_sort(j + 1, r, k - j + l - 1));
}

signed main() {
  vt n, k, x, y;
  cin >> n >> k >> x >> y;
  *num = 1;
  for (vt i = 0; i < n; ++i) {
    num[i + 1] = (num[i] * x + y) % Mod;
  }
  cout << quick_sort(1, n, k);
  return 0;
}