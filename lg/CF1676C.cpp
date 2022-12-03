#include <algorithm>
#include <iostream>
#include <vector>
#define tpt "%lld"
#define rtp(x) scanf(tpt, &x)

using namespace std;
using tp = long long;
constexpr bool _TESTS_ = 1;

namespace _SOL_ {
tp m;

tp Calc(string s, string t) {
  tp sum = 0;
  for (tp i = 0; i < m; ++i) {
    sum += t[i] > s[i] ? t[i] - s[i] : s[i] - t[i];
  }
  return sum;
}

signed main() {
  tp n, MIN = 0x7fffffffffffffff;
  scanf(tpt tpt, &n, &m);
  vector<string> v(n);
  for (auto&& i : v) {
    cin >> i;
  }
  // stable_sort(v.begin(), v.end());
  for (tp i = 0; i < n; ++i) {
    for (tp j = i + 1; j < n; ++j) {
      MIN = min(MIN, Calc(v[i], v[j]));
    }
  }
  cout << MIN << '\n';
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