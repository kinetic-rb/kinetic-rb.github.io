#include <algorithm>
#include <iostream>
#include <stack>

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
constexpr tp Hat_N = 2e5 + 3;

tp n, m, s, d;
tp r[Hat_N], l[Hat_N];

signed __PRE__() {
  return 0;
}

void READ() {
  tp N = 0;
  tp* v = new tp[Hat_N];
  re(n, m, s, d);
  for_each(v + 1, v + n + 1, [&](auto&& x) { re(x); });
  stable_sort(v + 1, v + n + 1);
  *v = -1;
  if (v[1] <= s) {
    throw "IMPOSSIBLE";
  }
  for (tp i = 1; i <= n; ++i) {
    if (v[i] - v[i - 1] > s + 1) {
      l[++N] = v[i];
    }
    r[N] = v[i];
  }
  n = N;
  delete[] v;
}

signed __CORE__() {
  try {
    tp loc = 0;
    READ();
    for (tp i = 1; i <= n; ++i) {
      if (r[i] - l[i] + 2 > d) {
        throw "IMPOSSIBLE";
      }
    }
    for (tp i = 1; i <= n; ++i) {
      cout << "RUN " << l[i] - loc - 1 << "
JUMP " << r[i] - l[i] + 2 << '\n';
      loc = r[i] + 1;
    }
    if (loc < m) {
      cout << "RUN " << m - loc;
    }
  } catch (...) {
    cout << "IMPOSSIBLE
";
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