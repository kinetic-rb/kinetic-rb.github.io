#include <iostream>

using namespace std;
using vt = long long;
constexpr vt N = 100003;

vt a[N];
vt res;

void merge_sort(vt l, vt r) {
  if (l >= r) {
    return;
  }
  vt mid = l + r >> 1;
  merge_sort(l, mid), merge_sort(mid + 1, r);
  vt *c = new vt[N], k, i, j;
  for (k = l, i = l, j = mid + 1; k <= r; ++k) {
    if (j > r || (i <= mid && a[i] < a[j])) {
      res += j - mid - 1;
      c[k] = a[i++];
    } else {
      c[k] = a[j++];
    }
  }
  copy(c + l, c + r + 1, a + l);
  delete[] c;
}

signed main() {
  vt n;
  cin >> n;
  for (vt i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  merge_sort(1, n);
  cout << res;
  return 0;
}