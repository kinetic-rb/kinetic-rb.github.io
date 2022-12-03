#include <algorithm>
#include <iostream>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 100003;

struct Rs {
  int l, r;

  bool operator<(const Rs& comp) const {
    if (l != comp.l) {
      return l < comp.l;
    }
    return r > comp.r;
  }
} m[Hat_N];

int main() {
  tp n, cnt = 0;
  cin >> n;
  for (tp i = 0; i < n; ++i) {
    tp x, y;
    cin >> x >> y;
    m[i].l = x - y;
    m[i].r = x + y;
  }
  stable_sort(m, m + n);
  for (tp i = 0; i < n; ++i) {
    static tp w = 0;
    if (m[i].r > w) {
      ++cnt;
      w = m[i].r;
    }
  }
  cout << cnt;
  return 0;
}