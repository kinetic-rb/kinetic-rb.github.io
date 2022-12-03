#include <iostream>
#include <algorithm>

using namespace std;

struct AC {
  int x, y;
} ap[5005];

int main() {
  int n, s, h, b, ans = 0;
  cin >> n >> s >> h >> b;
  h += b;
  for (int i = 0; i < n; i++)
    cin >> ap[i].x >> ap[i].y;
  stable_sort(ap, ap + n, [](const AC& x, const AC& y) {
    return x.y < y.y;
  });
  for (int i = 0; i < n; i++) {
    if (ap[i].x <= h)
      if (ap[i].y <= s) {
        ans++;
        s -= ap[i].y;
      }
    if (!s)
      break;
  }
  cout << ans;
  return 0;
}