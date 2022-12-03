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

tp calc(tp n, tp i) {
  tp tar = 0;
  while (n >= i) {
    tar += n /= i;
  }
  return tar;
}

signed __SOL__::main() {
  tp n, b, MIN = -1ull / 2;
  sf(tpt(2), n, b);
  for (tp i = 2; i * i <= b; ++i) {
    if (!(b % i)) {
      tp cnt = 0;
      while (!(b % i)) {
        b /= i;
        ++cnt;
      }
      MIN = min(MIN, calc(n, i) / cnt);
    }
  }
  if (b > 1) {
    MIN = min(MIN, calc(n, b));
  }
  cout << MIN;
  return 0;
}

signed __SOL__::PRE() {
  return 0;
}

//                                                               \
\u256d\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256e  \
\u2502   This Code Was Created By RBTree (https://rbtree.archi/)   \u2502  \
\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256f

/**
 * @bug This Program Will WA
 */
//\
 ___       ___         ___________     \
|\  \     |\  \       |\    ___   \
\ \  \    \ \  \      \ \   \|_\   \
 \ \  \  __\ \  \      \ \    ___   \
  \ \  \|\__\_\  \      \ \   \  \   \
   \ \____________\      \ \___\  \___\
    \|____________|       \|___|  |___|
//