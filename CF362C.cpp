#include <algorithm>
#include <cmath>
#include <iostream>

using tp = int32_t;
namespace ANONYMOUS {
tp re();
template <typename Typex>
void re(Typex&&);
template <typename Typex, typename... Typey>
void re(Typex&&, Typey&&...);
}  // namespace ANONYMOUS
using ANONYMOUS::re;
using namespace std;
constexpr bool __TESTS__ = 0;
constexpr tp Hat_N = 5003;

tp v[Hat_N], L[Hat_N][Hat_N], G[Hat_N][Hat_N];

signed __PRE__() {
  return 0;
}

signed __CORE__() {
  tp n, RP = 0, MIN, cnt = 0;
  re(n);
  for_each(v + 1, v + n + 1, [&](auto&& x) { x = re() + 1; });
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 1; j <= n; ++j) {
      L[i][j] = L[i - 1][j] + (v[i] < j);
      G[i][j] = G[i - 1][j] + (v[i] > j);
    }
    RP += G[i][v[i]];
  }
  MIN = RP;
  for (tp i = 1; i <= n; ++i) {
    for (tp j = i + 1; j <= n; ++j) {
      tp tar = RP - 
               G[i - 1][v[i]] - G[j - 1][v[j]] - L[j - 1][v[i]] + L[i][v[i]] + 
               G[i - 1][v[j]] + G[j - 1][v[i]] + L[j - 1][v[j]] - L[i][v[j]];
      if (tar < MIN) {
        MIN = tar;
        cnt = 0;
      }
      cnt += tar == MIN;
    }
  }
  cout << MIN << ' ' << cnt << '\n';
  return 0;
}

signed main() {
  static ::tp __PRE__ = ::__PRE__(), __TEST_COUNT__ = __TESTS__ ? re() : 1;
  return __TEST_COUNT__-- && (::main() || ::__CORE__()) ? -0b1ll : __PRE__;
}

namespace ANONYMOUS {
tp __Temp_Value__;
tp re() {
  re(__Temp_Value__);
  return __Temp_Value__;
}
void re(double&& __Value) {
  scanf("%lf", &__Value);
}
template <typename Typex>
void re(Typex&& __Value) {
  scanf("%d", &__Value);
}
template <typename Typex, typename... Typey>
void re(Typex&& __Value, Typey&&... __Another) {
  re(__Value);
  re(__Another...);
}
}  // namespace ANONYMOUS

//                                                               \
\u256d\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256e  \
\u2502     This Code Was Created By RBTree (https://rbtree.cc)     \u2502  \
\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256f
//