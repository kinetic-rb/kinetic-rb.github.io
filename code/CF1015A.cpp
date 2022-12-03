#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;
using vt = long long;
constexpr vt Hat_N = 103;

vector state(Hat_N, false);

list<vt> res;

signed main() {
  vt n, m;
  cin >> n >> m;
  while (n--) {
    vt l, r;
    for (cin >> l >> r; l <= r; ++l) {
      state[l] = true;
    }
  }
  for (vt i = 1; i <= m; ++i) {
    if (!state[i]) {
      res.push_back(i);
    }
  }
  cout << res.size() << '\n';
  for (auto&& i : res) {
    cout << i << ' ';
  }
  return 0;
}