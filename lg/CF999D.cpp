#include <iostream>
#include <set>

using namespace std;
using vt = long long;
constexpr vt Hat_N = 200003, Hat_M = 200003;

vt num[Hat_N], cnt[Hat_M];

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  set<vt> r;
  vt n, m, k, res = 0;
  cin >> n >> m;
  k = n / m;
  for (vt i = 0; i < m; ++i) {
    r.insert(i);
  }
  for (vt i = 0; i < n; ++i) {
    cin >> num[i];
  }
  for (vt i = 0; i < n; ++i) {
    vt x;
    if (num[i] % m > *r.rbegin()) {
      x = *r.begin();
      res += (x - num[i] % m + m);
      num[i] += (x - num[i] % m + m);
    } else {
      x = *r.lower_bound(num[i] % m);
      res += x - num[i] % m;
      num[i] += x - num[i] % m;
    }
    ++cnt[x];
    if (cnt[x] == k) {
      r.erase(x);
    }
  }
  cout << res << '\n';
  for (vt i = 0; i < n; ++i) {
    cout << num[i] << ' ';
  }
  return 0;
}