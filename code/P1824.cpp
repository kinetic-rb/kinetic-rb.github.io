#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[1000010], n, c;

inline bool p(const int &d) {
  register int k = 0, last = -0x3fffffff;
  for (register int i = 1; i <= n; i++) {
    if (a[i] - last >= d) {
      last = a[i];
      k++;
    }
  }
  return k >= c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> c;
  for (register int i = 1; i <= n; i++)
    cin >> a[i];
  stable_sort(a + 1, a + n + 1);
  register int l = 0, r = a[n], ans = -0x7fffffff, mid;
  while (l <= r) {
    mid = l + ((r - l) >> 1);
    if (p(mid)) {
      ans = max(ans, mid);
      l = mid + 1;
    }
    else
      r = mid - 1;
  }
  cout << ans;
  return 0;
}