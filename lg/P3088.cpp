#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using tp = long long;

signed main() {
  tp n, d, l = 0, cnt = 0;
  scanf("%lld%lld", &n, &d);
  set<tp> s1, s2;
  multiset<tp> m;
  vector<pair<tp, tp>> v(n);
  for (auto&& i : v) {
    scanf("%lld%lld", &i.first, &i.second);
  }
  stable_sort(v.begin(), v.end());
  m.insert(v[0].second);
  for (tp i = 1; i < n; ++i) {
    while (m.size() && v[l].first < v[i].first - d) {
      m.erase(m.find(v[l++].second));
    }
    if (m.size() && *m.rbegin() >= v[i].second * 2) {
      s1.insert(i);
    }
    m.insert(v[i].second);
  }
  m.clear();
  m.insert(v[n - 1].second);
  l = n - 1;
  for (tp i = n - 2; ~i; --i) {
    while (m.size() && v[l].first > v[i].first + d) {
      m.erase(m.find(v[l--].second));
    }
    if (m.size() && *m.rbegin() >= v[i].second * 2) {
      s2.insert(i);
    }
    m.insert(v[i].second);
  }
  for (auto&& i : s1) {
    cnt += s2.count(i);
  }
  cout << cnt << '\n';
  return 0;
}