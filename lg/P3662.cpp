#include <iostream>
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

namespace __SOL__ {
signed main() {
  tp n, k, b, MIN = 0x7fffffffffffffff;
  sf(tpt(3), n, k, b);
  vector<bool> v(n + 1, 0);
  vector<tp> ps(n + 1, 0);
  for (tp i = 0; i < n; ++i) {
    tp x;
    rtp(x);
    v[x] = 1;
  }
  for (tp i = 1; i <= n; ++i) {
    ps[i] = ps[i - 1] + v[i];
  }
  for (tp i = k; i <= n; ++i) {
    MIN = min(MIN, ps[i] - ps[i - k]);
  }
  cout << MIN;
  return 0;
}

signed PRE() {
  return 0;
}
}  // namespace __SOL__

signed main() {
  static tp __P__ = __SOL__::PRE(), __T__ = 1, __R__ = sf(tpt(__MTCS__), __T__);
  return __T__-- && (main() || __SOL__::main()) ? -1 : __P__;
}

//                                                               \
\u256d\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256e  \
\u2502   This Code Was Created By RBTree (https://rbtree.archi/)   \u2502  \
\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256f
//