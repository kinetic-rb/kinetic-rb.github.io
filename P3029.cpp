#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using tp = long long;

signed main() {
  tp n, MIN = -1ull / 2, c = 0;
  set<tp> all;
  map<tp, tp> cnt;
  scanf("%lld", &n);
  vector<pair<tp, tp>> v(n);
  for (tp i = 0; i < n; ++i) {
    scanf("%lld%lld", &v[i].first, &v[i].second);
    all.insert(v[i].second);
  }
  stable_sort(v.begin(), v.end());
  for (tp l = 0, r = 0; r < n; ++r) {
    c += !cnt[v[r].second];
    ++cnt[v[r].second];
    while (cnt[v[l].second] > 1) {
      --cnt[v[l++].second];
    }
    if (c == all.size()) {
      MIN = min(MIN, v[r].first - v[l].first);
    }
  }
  cout << MIN;
  return 0;
}