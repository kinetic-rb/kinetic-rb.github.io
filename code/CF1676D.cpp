#include <algorithm>
#include <iostream>
#include <vector>
#define tpt "%lld"
#define rtp(x) scanf(tpt, &x)

using namespace std;
using tp = long long;
constexpr bool _TESTS_ = 1;

namespace _SOL_ {
signed main() {
  tp n, m, MAX = 0;
  scanf(tpt tpt, &n, &m);
  vector<pair<tp, tp>> dir = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
  vector<vector<tp>> v(n, vector<tp>(m));
  for (auto&& i : v) {
    for (auto&& j : i) {
      rtp(j);
    }
  }
  for (tp i = 0; i < n; ++i) {
    for (tp j = 0; j < m; ++j) {
      tp sum = 0;
      for (auto&& [px, py] : dir) {
        tp x = i, y = j;
        while (~x && ~y && x < n && y < m) {
          sum += v[x][y];
          x += px;
          y += py;
        }
      }
      MAX = max(MAX, sum - v[i][j] * 3);
    }
  }
  cout << MAX << '\n';
  return 0;
}

signed _PRE_() {
  return 0;
}
}  // namespace _SOL_

signed main() {
  static tp _P_ = _SOL_::_PRE_(), T_ = 1, _R_ = scanf(_TESTS_ ? tpt : "", &T_);
  return T_-- && (main() || _SOL_::main()) ? -1 : _P_;
}

//                                                               \
\u256d\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256e  \
\u2502   This Code Was Created By RBTree (https://rbtree.archi/)   \u2502  \
\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256f
//