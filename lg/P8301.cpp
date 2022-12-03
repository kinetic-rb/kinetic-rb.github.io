#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#define rtp(__VALUE__) scanf("%lld", &__VALUE__)

using namespace std;
using tp = long long;
constexpr bool __MTCS__ = 0;

namespace {
template <typename _Typex>
string tpt(_Typex __value = 1, const string& __type = "%lld") {
  size_t __count = static_cast<size_t>(__value);
  string __target;
  __target.reserve(__count << 2ll);
  while (__count--) {
    __target += __type;
  }
  return __target;
}

template <typename... _Typey>
signed sf(const string& __input, _Typey&... __value) {
  return ::scanf(__input.c_str(), &__value...);
}
}  // namespace

namespace _SOL_ {
signed main() {
  tp n;
  rtp(n);
  vector<char> v1(n), v2(n);
  for (auto&& i : v1) {
    cin >> i;
    i &= 15;
  }
  for (auto&& i : v2) {
    cin >> i;
    i &= 15;
  }
  cout << abs(
      accumulate(v1.begin(), v1.end(), -accumulate(v2.begin(), v2.end(), 0)));
  return 0;
}

signed _PRE_() {
  return 0;
}
}  // namespace _SOL_

signed main() {
  static tp __P__ = _SOL_::_PRE_(), __T__ = 1, __R__ = sf(tpt(__MTCS__), __T__);
  return __T__-- && (main() || _SOL_::main()) ? -1 : __P__;
}

//                                                               \
\u256d\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256e  \
\u2502   This Code Was Created By RBTree (https://rbtree.archi/)   \u2502  \
\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256f
//