#include <algorithm>
#include <cstdio>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define __RV__ "%lld"
#define rtp(__VALUE__) scanf(__RV__, &__VALUE__)

namespace {
template <typename _Typex>
std::string tpt(_Typex __value = 1, const std::string& __type = __RV__) {
  size_t __count = static_cast<size_t>(__value);
  std::string __target;
  __target.reserve(__count * __type.size());
  while (__count--) {
    __target += __type;
  }
  return __target;
}

template <typename... _Typex>
signed sf(const std::string& __input, _Typex&... __value) {
  return ::scanf(__input.c_str(), &__value...);
}
}  // namespace

using namespace std;
using tp = long long;
constexpr bool __MTCS__ = 0;

namespace __SOL__ {
signed main();
signed PRE();
}  // namespace __SOL__

signed main() {
  static tp __P__ = __SOL__::PRE(), __T__ = __MTCS__ ? (rtp(__T__), __T__) : 1;
  return __T__-- && (main() || __SOL__::main()) ? -1 : __P__;
}

/**
 * @brief Find number x and y, make ax + by = gcd(a, b)
 *
 * @return tp gcd(a, b)
 */
template <typename _Typex>
_Typex exgcd(_Typex a, _Typex b, _Typex& x, _Typex& y) {
  if (!b) {
    tie(x, y) = make_pair(1, 0);
    return a;
  } else {
    tp gcd = exgcd(b, a % b, x, y);
    tie(x, y) = make_pair(y, x - (a / b) * y);
    return gcd;
  }
}

signed __SOL__::main() {
  tp n;
  rtp(n);
  vector<tp> c(n), p(n), l(n);
  for (tp i = 0; i < n; ++i) {
    sf(tpt(3), c[i], p[i], l[i]);
  }
  for (tp m = *max_element(c.begin(), c.end());; ++m) {
    bool f = 1;
    for (tp i = 0; i < n && f; ++i) {
      for (tp j = i + 1; j < n; ++j) {
        tp a = p[j] - p[i], b = m, x, y, gcd = __gcd(a, b);
        if (!((c[i] - c[j]) % gcd)) {
          tie(a, b) = make_pair(a / gcd, b / gcd);
          exgcd(a, b, x, y);
          b = abs(b);
          if (x = ((x * ((c[i] - c[j]) / gcd)) % b + b) % b; !x) {
            x += b;
          }
          if (x <= min(l[i], l[j])) {
            f = 0;
            break;
          }
        }
      }
    }
    if (f) {
      cout << m;
      return 0;
    }
  }
  return 0;
}

signed __SOL__::PRE() {
  return 0;
}

//                                                               \
\u256d\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256e  \
\u2502   This Code Was Created By RBTree (https://rbtree.archi/)   \u2502  \
\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256f
//