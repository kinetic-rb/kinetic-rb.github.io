#include <algorithm>
#include <iostream>
#define TPT "%lld"
#define RTP(x) scanf(TPT, &x)

using namespace std;
using tp = long long;
constexpr bool __TESTS__ = 0;
constexpr tp Hat_N = 1e5 + 3;

template <typename _Typex, typename _Typey, typename _Function>
_Typex ISearch(_Typex __low, _Typey __high, _Function __f) {
  double __factor = 0.5, __power = 0;
  while (__low <= __high) {
    _Typey __middle = (__high + __low) * __factor;
    if (__f(__middle)) {
      __low = __middle + 1;
      __factor -= __power;
    } else {
      __high = __middle - 1;
      __factor += __power;
    }
    __power /= 2;
  }
  return __low;
}
tp v[Hat_N];

signed __CORE__() {
  tp n, m;
  scanf(TPT TPT, &n, &m);
  for_each(v + 1, v + n + 1, [](auto&& x) { RTP(x); });
  while (m--) {
    tp x;
    RTP(x);
    cout << ISearch(1, n, [&](auto&& l) { return v[l] < x; }) << '\n';
  }
  return 0;
}

signed __PRE__() {
  return 0;
}

signed main() {
  static tp p = __PRE__(), t = 1, r = scanf(__TESTS__ ? "%lld" : "", &t);
  return t-- && (main() || __CORE__()) ? -1 : p;
}

//                                                               \
\u256d\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256e  \
\u2502   This Code Was Created By RBTree (https://rbtree.archi/)   \u2502  \
\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256f
//