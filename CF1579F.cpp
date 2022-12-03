#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rtp(__VALUE__) scanf("%lld", &__VALUE__);

using namespace std;
using tp = long long;
constexpr bool __MTCS__ = 1;

namespace {
template <typename _Typex>
string tpt(_Typex __value = 1, const string& __type = "%lld") {
  size_t __count = static_cast<size_t>(__value);
  string __target;
  __target.reserve(__count * __type.size());
  while (__count--) {
    __target += __type;
  }
  return __target;
}

template <typename... _Typex>
signed sf(const string& __input, _Typex&... __value) {
  return ::scanf(__input.c_str(), &__value...);
}
}  // namespace

namespace __SOL__{
signed main() {
  tp n, d, gcd, cnt, tar = 0;
  sf(tpt(2), n, d);
  gcd = __gcd(n, d);
  cnt = n / gcd;
  vector<tp> v(n);
        for (auto&& i : v) {
    rtp(i);
  }
  for (tp i = 0; i < gcd; ++i) {
    tp count = 0, MAX = 0;
    vector<tp> sh;
    for (tp j = 1; j <= cnt; ++j) {
      sh.push_back(v[(i + j * d) % n]);
    }
    for (tp j = 0; j < cnt; ++j) {
      sh.push_back(sh[j]);
    }
    for (auto&& i : sh) {
      count += i;
      count *= i;
      MAX = max(MAX, count);
    }
    tar = max(tar, MAX);
  }
  cout << (tar == cnt * 2 ? -1 : tar) << '\n';
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