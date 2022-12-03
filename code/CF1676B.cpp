#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#define tp_t "%lld"
#define rtp(x) scanf(tp_t, &x)

using namespace std;
using tp = long long;
constexpr bool _TESTS_ = 1;

namespace _SOL_ {
signed main() {
  tp n, MIN = 0x7fffffff;
  rtp(n);
  vector<tp> v(n);
  for (auto&& i : v) {
    rtp(i);
  }
  for_each(v.begin(), v.end(), [&MIN](auto&& x) { MIN = min(MIN, x); });
  cout << accumulate(v.begin(), v.end(), -MIN * n) << '\n';
  return 0;
}

signed _PRE_() {
  return 0;
}
}  // namespace _SOL_

signed main() {
  static tp _P_ = _SOL_::_PRE_(), T_ = 1, _R_ = scanf(_TESTS_ ? tp_t : "", &T_);
  return T_-- && (main() || _SOL_::main()) ? -1 : _P_;
}

//                                                               \
\u256d\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256e  \
\u2502   This Code Was Created By RBTree (https://rbtree.archi/)   \u2502  \
\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256f
//