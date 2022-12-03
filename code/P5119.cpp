#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
using tp = long long;

tp n, m, c;
vector<tp> v;

bool check(tp w) {
  tp l = v.front(), in = 0, buses = 1;
  for (tp i = 1; i < n; ++i) {
    if (v[i] - l > w || i - in >= c) {
      tie(buses, l, in) = make_tuple(buses + 1, v[i], i);
    }
  }
  return buses <= m;
}

signed main() {
  tp l = 0, h = 1ll << 60;
  scanf("%lld%lld%lld", &n, &m, &c);
  v.resize(n);
  for (auto&& i : v) {
    scanf("%lld", &i);
  }
  stable_sort(v.begin(), v.end());
  while (l <= h) {
    tp mid = l + h >> 1;
    if (check(mid)) {
      h = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << l;
  return 0;
}