#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#define tpt "%lld"
#define rtp(x) scanf(tpt, &x)

using namespace std;
using tp = long long;
constexpr bool _TESTS_ = 1;

namespace _SOL_ {
signed main() {
  tp n, m, sum;
  scanf(tpt tpt, &n, &m);
  vector<tp> v(n);
  for (auto&& i : v) {
    rtp(i);
  }
  sum = accumulate(v.begin(), v.end(), 0);
  stable_sort(v.rbegin(), v.rend());
  for_each(v.begin() + 1, v.end(), [](auto&& x) { x += *prev(&x); });
  while (m--) {
    tp x, i, totol = 0;
    rtp(x);
    if (x > sum) {
      puts("-1");
      continue;
    }
    cout << lower_bound(v.begin(), v.end(), x) - v.begin() + 1 << '\n';
  }
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