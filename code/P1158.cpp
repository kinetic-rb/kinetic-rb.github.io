#include <iostream>
#include <algorithm>
#define dist(x1, y1, x2, y2) (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)

using namespace std;

struct CE {
  int l1, l2;
} f[110000];

int main() {
  int n, x1, x2, y1, y2, a, b, ans, hei = -1;
  std::ios::sync_with_stdio(false);
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    f[i].l1 = dist(x1, y1, a, b);
    f[i].l2 = dist(x2, y2, a, b);
  }
  stable_sort(f + 1, f + n + 1, <:](const CE & a, const CE & b) { return a.l1 < b.l1; });
  ans = f[n].l1;
  for (int i = n - 1; i > 0; i--) {
    ans = min(ans, (hei = max(hei, f[i + 1].l2)) + f[i].l1);
  }
  cout << ans;
  return 0;
}