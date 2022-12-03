#include <algorithm>
#include <cstring>
#include <iostream>

using tp = long long;
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
constexpr tp Hat_N = 5004;

tp v[Hat_N], f[Hat_N >> 1][3];

signed __PRE__() {
  return 0;
}

signed __CORE__() {
  tp n;
  memset(f, 0x3f, sizeof f);
  f[0][0] = f[1][1] = 0;
  re(n);
  for_each(v + 1, v + n + 1, [](auto& x) { re(x); });
  for (tp i = 2; i <= n; ++i) {
    for (tp j = i + 1 >> 1; j; --j) {
      f[j][0] = min(f[j][0], f[j][2]);
      f[j][2] = f[j][1] + max(0ll, v[i] - v[i - 1] + 1);
      f[j][1] =
          min(f[j - 1][0] + max(0ll, v[i - 1] - v[i] + 1),
              f[j - 1][2] + max(0ll, min(v[i - 1], v[i - 2] - 1) - v[i] + 1));
    }
  }
  for (tp i = 1; i <= n + 1 >> 1; ++i) {
    cout << min(f[i][0], min(f[i][1], f[i][2])) << ' ';
  }
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
  scanf("%lld", &__Value);
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